import java.io.IOException; // 导入处理输入输出异常的类
import java.net.ServerSocket; // 导入用于创建服务器端Socket的类
import java.net.Socket; // 导入用于创建客户端Socket的类
import java.util.concurrent.ExecutorService; // 导入用于创建线程池的接口
import java.util.concurrent.Executors; // 导入用于创建ExecutorService实现的类
import java.util.logging.Level; // 导入用于设置日志记录级别的类
import java.util.logging.Logger; // 导入用于记录日志信息的类

//启动服务器，创建线程池并监听端口，处理客户端请求(服务器主类)
public class SimpleWebServer {
    // 从配置文件获取服务器端口号，默认值为8080
    private static final int PORT = Config.getIntProperty("port", 8080);
    // 从配置文件获取线程池大小，默认值为10
    private static final int THREAD_POOL_SIZE = Config.getIntProperty("thread_pool_size", 10);
    // 创建日志记录器实例
    private static final Logger logger = Logger.getLogger(SimpleWebServer.class.getName());

    // 服务器主函数
    public static void main(String[] args) {
        // 设置全局日志记录级别
        Logger.getLogger("").setLevel(Config.getLogLevel());
        // 创建具有固定线程数的线程池
        ExecutorService threadPool = Executors.newFixedThreadPool(THREAD_POOL_SIZE);

        try (ServerSocket serverSocket = new ServerSocket(PORT)) { // 创建服务器Socket并绑定到指定端口
            logger.info("Web服务器启动，监听端口: " + PORT); // 记录服务器启动信息

            // 无限循环，持续监听客户端连接
            while (true) {
                Socket clientSocket = serverSocket.accept(); // 接受客户端连接请求
                // 将客户端连接交给线程池中的一个线程处理
                threadPool.execute(new ClientHandler(clientSocket));
            }
        } catch (IOException e) { // 捕获IO异常
            logger.log(Level.SEVERE, "服务器错误", e); // 记录服务器错误信息
        }
    }
}
