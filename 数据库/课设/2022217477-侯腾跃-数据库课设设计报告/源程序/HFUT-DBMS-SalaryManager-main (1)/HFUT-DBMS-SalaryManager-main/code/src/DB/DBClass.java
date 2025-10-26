package DB;


//这是数据库连接模块
import java.sql.*;
public class DBClass {
    static String DBDRIVER= "com.mysql.cj.jdbc.Driver";
    static String DBURL="jdbc:mysql://localhost:3306/hr_system?characterEncoding=utf-8&useSSL=false&serverTimezone=Asia/Shanghai";
    static String DBUSER= "root";
    static String DBPASSWORD= "123456";
    public static Connection get_con(){
        Connection conn=null;
        try{
            Class.forName(DBDRIVER);
            conn=DriverManager.getConnection(DBURL,DBUSER,DBPASSWORD);
        }catch (Exception e){
            System.out.println("数据库连接失败：" + e.getMessage());
        }
        return conn;
    }
}
