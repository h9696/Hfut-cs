import java.io.IOException; // 导入处理输入输出异常的类
import java.io.InputStream; // 导入处理输入流的类
import java.util.Properties; // 导入处理属性文件的类
import java.util.logging.Level; // 导入日志记录级别的类
import java.util.logging.Logger; // 导入日志记录器的类

//加载并提供配置文件中的配置项(配置加载)
public class Config {
    // 用于存储配置信息的Properties对象
    private static final Properties properties = new Properties();
    // 用于记录日志的Logger对象
    private static final Logger logger = Logger.getLogger(Config.class.getName());

    // 静态代码块，在类加载时执行一次，用于加载配置文件
    static {
        // 尝试读取配置文件config.properties
        try (InputStream input = Config.class.getClassLoader().getResourceAsStream("config.properties")) {
            // 尝试读取配置文件config.properties
            if (input == null) { // 如果未找到配置文件
                throw new IOException("配置文件未找到"); // 抛出IO异常
            }
            // 加载配置文件内容到Properties对象中
            properties.load(input); // 加载配置文件中的属性
        } catch (IOException e) { // 捕获IO异常
            // 记录加载配置文件时的错误信息
            logger.log(Level.SEVERE, "加载配置文件失败", e); // 记录加载配置文件失败的信息
        }
    }

    // 获取web根目录配置，获取指定key对应的配置值
    public static String getProperty(String key) {
        return properties.getProperty(key); // 获取指定键的属性值
    }

    // 获取服务器端口号配置，获取指定key对应的配置值，并将其转换为整数，如果不存在则返回默认值
    public static int getIntProperty(String key, int defaultValue) {
        String value = properties.getProperty(key); // 获取指定键的属性值
        return value != null ? Integer.parseInt(value) : defaultValue; // 如果属性值不为空，则解析为整数；否则返回默认值
    }

    // 获取日志级别配置，并将其转换为Level对象
    public static Level getLogLevel() {
        String logLevel = properties.getProperty("log.level", "INFO"); // 获取日志级别的属性值，默认为INFO
        return Level.parse(logLevel.toUpperCase()); // 将日志级别转换为Level对象并返回
    }
}
