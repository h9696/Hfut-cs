import java.io.File; // 导入File类
import java.util.LinkedHashMap; // 导入LinkedHashMap类
import java.util.Map; // 导入Map接口

//实现一个简单的文件内容缓存，以提高文件读取效率(简单缓存类)
public class SimpleCache {
    // 最大缓存大小
    private final int maxSize;
    // 用于存储缓存内容的Map
    private final Map<String, byte[]> cache;

    // 构造函数，接受最大缓存大小
    public SimpleCache(int maxSize) {
        this.maxSize = maxSize; // 设置缓存的最大容量
        // 初始化缓存Map，使用LinkedHashMap实现，设置访问顺序
        this.cache = new LinkedHashMap<String, byte[]>(maxSize, 0.75f, true) {
            // 重写LinkedHashMap的removeEldestEntry方法
            @Override
            protected boolean removeEldestEntry(Map.Entry<String, byte[]> eldest) {
                // 当缓存的大小超过最大容量时，移除最旧的条目
                return size() > SimpleCache.this.maxSize;
            }
        };
    }

    // 从缓存中获取文件内容
    public byte[] get(File file) {
        // 通过文件的绝对路径作为键，从缓存中获取对应的字节数组
        return cache.get(file.getAbsolutePath());
    }

    // 将文件内容放入缓存
    public void put(File file, byte[] content) {
        // 通过文件的绝对路径作为键，将文件内容的字节数组存入缓存
        cache.put(file.getAbsolutePath(), content);
    }
}
