//定义HTTP状态码及其对应的描述(HTTP状态码枚举类)
public enum HttpStatus {
    // 枚举常量，表示HTTP状态码及其对应的描述
    OK(200, "OK"), // 成功请求
    BAD_REQUEST(400, "Bad Request"), // 错误请求
    NOT_FOUND(404, "Not Found"), // 未找到资源
    METHOD_NOT_ALLOWED(405, "Method Not Allowed"); // 方法不允许

    // HTTP状态码
    private final int code; // HTTP状态码
    // HTTP状态描述
    private final String reason; // 对应的描述

    // 枚举构造函数，用于初始化枚举常量
    HttpStatus(int code, String reason) {
        this.code = code; // 设置HTTP状态码
        this.reason = reason; // 设置对应的描述
    }

    // 获取HTTP状态码
    public int getCode() {
        return code; // 返回HTTP状态码
    }

    // 获取HTTP状态描述
    public String getReason() {
        return reason; // 返回对应的描述
    }
}
