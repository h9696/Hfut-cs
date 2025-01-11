import java.io.*; // 导入Java IO库
import java.net.Socket; // 导入Socket类
import java.nio.charset.StandardCharsets; // 导入标准字符集
import java.nio.file.Files; // 导入Files类
import java.text.SimpleDateFormat; // 导入SimpleDateFormat类
import java.util.*; // 导入Java util库
import java.util.logging.Level; // 导入日志级别类
import java.util.logging.Logger; // 导入日志记录器类

//处理具体的客户端请求，读取请求行，解析请求方法和路径，读取文件并返回响应(客户端处理类)
public class ClientHandler implements Runnable {
    // 从配置文件获取web根目录
    private static final String WEB_ROOT = Config.getProperty("webroot");
    // Logger对象用于记录日志
    private static final Logger logger = Logger.getLogger(ClientHandler.class.getName());
    // 创建MIME类型映射
    private static final Map<String, String> MIME_TYPES = new HashMap<>();
    // 创建缓存对象
    private static final SimpleCache cache = new SimpleCache(100);

    static {
        // 初始化MIME类型映射
        MIME_TYPES.put("html", "text/html");
        MIME_TYPES.put("htm", "text/html");
        MIME_TYPES.put("css", "text/css");
        MIME_TYPES.put("js", "application/javascript");
        MIME_TYPES.put("png", "image/png");
        MIME_TYPES.put("jpg", "image/jpeg");
        MIME_TYPES.put("jpeg", "image/jpeg");
        MIME_TYPES.put("gif", "image/gif");
        // 可以根据需要扩展更多MIME类型
    }

    // 客户端Socket对象
    private Socket clientSocket;

    // 构造函数，接受客户端Socket
    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        // 处理客户端请求
        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
             OutputStream rawOut = clientSocket.getOutputStream();
             PrintWriter out = new PrintWriter(new OutputStreamWriter(rawOut, StandardCharsets.UTF_8))) {

            // 读取请求行
            String requestLine = in.readLine();
            logger.info("收到请求: " + requestLine); // 记录收到的请求

            // 读取请求行
            if (requestLine == null || requestLine.isEmpty()) { // 如果请求行为空
                sendErrorResponse(out, HttpStatus.BAD_REQUEST); // 发送400错误响应
                return;
            }

            // 解析请求行
            String[] tokens = requestLine.split(" "); // 分割请求行
            if (tokens.length < 3) { // 如果请求行格式不正确
                sendErrorResponse(out, HttpStatus.BAD_REQUEST); // 发送400错误响应
                return;
            }

            // 获取请求方法和文件名
            String method = tokens[0]; // 请求方法
            String fileName = tokens[1].substring(1); // 请求的文件名，去掉开头的 '/'

            // 如果请求的是根目录，返回默认文件
            if (fileName.isEmpty()) { // 如果文件名为空
                fileName = "index.html"; // 设置默认文件
            }

            // 获取请求文件的绝对路径
            File file = new File(WEB_ROOT, fileName).getCanonicalFile(); // 获取文件的规范路径
            if (!file.getPath().startsWith(new File(WEB_ROOT).getCanonicalPath())) { // 防止路径遍历攻击
                sendErrorResponse(out, HttpStatus.NOT_FOUND); // 发送404错误响应
                return;
            }

            // 根据请求方法进行处理
            switch (method) {
                case "GET":
                    handleGetRequest(file, out, rawOut); // 处理GET请求
                    break;
                case "HEAD":
                    handleHeadRequest(file, out); // 处理HEAD请求
                    break;
                case "POST":
                    handlePostRequest(file, in, out); // 处理POST请求
                    break;
                default:
                    sendErrorResponse(out, HttpStatus.METHOD_NOT_ALLOWED); // 发送405错误响应
                    break;
            }
        } catch (IOException e) { // 捕获IO异常
            logger.log(Level.SEVERE, "客户端处理错误", e); // 记录错误信息
        } finally {
            try {
                clientSocket.close(); // 尝试关闭客户端Socket
            } catch (IOException e) { // 捕获IO异常
                logger.log(Level.WARNING, "无法关闭套接字", e); // 记录警告信息
            }
        }
    }

    // 处理GET请求
    private void handleGetRequest(File file, PrintWriter out, OutputStream rawOut) throws IOException {
        byte[] cachedContent = cache.get(file); // 尝试从缓存获取文件内容
        if (cachedContent != null) { // 如果缓存命中
            sendOkResponse(out, file); // 发送200响应
            rawOut.write(cachedContent); // 发送缓存内容
        } else {
            if (file.exists() && !file.isDirectory()) { // 如果文件存在且不是目录
                sendOkResponse(out, file); // 发送200响应
                byte[] fileContent = Files.readAllBytes(file.toPath()); // 读取文件内容
                cache.put(file, fileContent); // 将文件内容放入缓存
                rawOut.write(fileContent); // 发送文件内容
            } else {
                sendErrorResponse(out, HttpStatus.NOT_FOUND); // 发送404错误响应
            }
        }
    }

    // 处理HEAD请求
    private void handleHeadRequest(File file, PrintWriter out) throws IOException {
        if (file.exists() && !file.isDirectory()) { // 如果文件存在且不是目录
            sendOkResponse(out, file); // 发送200响应
        } else {
            sendErrorResponse(out, HttpStatus.NOT_FOUND); // 发送404错误响应
        }
    }

    // 处理POST请求
    private void handlePostRequest(File file, BufferedReader in, PrintWriter out) throws IOException {
        // 读取请求体并处理
        StringBuilder requestBody = new StringBuilder();
        String line;
        while ((line = in.readLine()) != null && !line.isEmpty()) {
            requestBody.append(line).append("\n");
        }
        // 这里可以实现处理逻辑
        sendOkResponse(out, file); // 示例返回响应
    }

    // 发送200 OK响应
    private void sendOkResponse(PrintWriter out, File file) throws IOException {
        String contentType = getContentType(file.getName()); // 获取文件的内容类型
        out.println("HTTP/1.1 " + HttpStatus.OK.getCode() + " " + HttpStatus.OK.getReason()); // 发送状态行
        out.println("Content-Type: " + contentType); // 发送内容类型
        out.println("Content-Length: " + file.length()); // 发送内容长度
        out.println("Connection: close"); // 发送连接关闭
        out.println("Date: " + getServerTime()); // 发送日期
        out.println("Server: SimpleWebServer"); // 发送服务器信息
        out.println(); // 空行，表示头部结束
        out.flush(); // 刷新输出流
    }

    // 发送错误响应
    private void sendErrorResponse(PrintWriter out, HttpStatus status) {
        out.println("HTTP/1.1 " + status.getCode() + " " + status.getReason()); // 发送状态行
        out.println("Content-Type: text/html"); // 发送内容类型
        out.println("Connection: close"); // 发送连接关闭
        out.println("Date: " + getServerTime()); // 发送日期
        out.println("Server: SimpleWebServer"); // 发送服务器信息
        out.println(); // 空行，表示头部结束
        out.println("<html><body><h1>" + status.getCode() + " " + status.getReason() + "</h1></body></html>"); // 发送错误信息
        out.flush(); // 刷新输出流
    }

    // 获取文件的MIME类型
    private String getContentType(String fileName) {
        String extension = "";
        int i = fileName.lastIndexOf('.');
        if (i > 0) {
            extension = fileName.substring(i + 1).toLowerCase(); // 获取文件扩展名
        }
        return MIME_TYPES.getOrDefault(extension, "application/octet-stream"); // 返回对应的MIME类型，默认为二进制流
    }

    // 获取文件扩展名
    private String getServerTime() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("EEE, dd MMM yyyy HH:mm:ss z", Locale.US); // 创建日期格式化对象
        dateFormat.setTimeZone(TimeZone.getTimeZone("GMT")); // 设置时区为GMT
        return dateFormat.format(new Date()); // 返回格式化的当前时间
    }
}
