package test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBTest {

    // 定义数据库连接参数
    private static final String URL = "jdbc:mysql://localhost:3306/hr_system?useSSL=false&serverTimezone=Asia/Shanghai";
    private static final String USER = "root";
    private static final String PASSWORD = "123456";

    public static void main(String[] args) {
        Connection connection = null;
        try {
            // 加载数据库驱动
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 获取数据库连接
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
            System.out.println("数据库连接成功！");

        } catch (ClassNotFoundException e) {
            System.err.println("找不到数据库驱动！");
            e.printStackTrace();
        } catch (SQLException e) {
            System.err.println("数据库连接失败！");
            e.printStackTrace();
        } finally {
            // 关闭数据库连接
            if (connection != null) {
                try {
                    connection.close();
                    System.out.println("数据库连接已关闭。");
                } catch (SQLException e) {
                    System.err.println("关闭数据库连接时出错！");
                    e.printStackTrace();
                }
            }
        }
    }
}

