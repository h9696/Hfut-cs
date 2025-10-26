<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/1
  Time: 17:03
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="DB.DBClass"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="style/css.css"/>
        <title>员工工资管理系统――删除页面</title>
    </head>
    <body>

        <%
        if (session.getAttribute("uname") != null) {
                        // 用户已登陆
        %>	
        <%
            Connection conn = null;
            PreparedStatement pstmt = null;
            // 接收参数
            int id = 0;
            String keyName = null;
            String table = null;
            id = Integer.parseInt(request.getParameter("id"));
            table = request.getParameter("table");
            keyName = request.getParameter("keyName");
            String sql = "DELETE FROM " + table + " WHERE " + keyName + "=?";
            boolean flag = true;
            conn=new DBClass().get_con();
            pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, id);// 设置删除条件
            try {
                pstmt.executeUpdate();
            } catch (SQLException e) {
                flag = false;
                String constraintName = e.getSQLState();
                if (constraintName.equals("23000")) {//检测到违反外键约束
        %>
                <div class="container">
                    <div class="infoBox">
                        <div>数据删除失败，存在有与该数据相关联的其他数据！<br><br><br>
                            <div><a href="list_employee.jsp">取消删除</a></div><br>
                        </div>
                    </div>
                </div>
        <%
                }//end 检测违反外键约束
            } finally {
                pstmt.close();
                conn.close();
            }
        %>
        <%
            if (flag) {
        %>
                <div class="container">
                    <div class="infoBox">
                        <div>数据删除成功，两秒后跳转到列表页！！！<br><br>
                            <div>如果没有跳转，请按<a href="list_employee.jsp">这里</a>！！！</div>
                        </div>
                    </div>
                </div>
        <%
                response.setHeader("refresh", "2;URL=list_employee.jsp");
            }//end 数据删除成功
        } else {
            // 用户未登陆，提示用户登陆，并跳转
            response.setHeader("refresh", "2;URL=login.jsp");
        %>
            <div class="container">
                <div class="infoBox">
                    您还未登陆，请先登陆！！！<br>
                    两秒后自动跳转到登陆窗口！！！<br>
                    如果没有跳转，请按<a href="login.jsp">这里</a>！！！<br>
                </div>
            </div>
        <%
        }//end 检测用户是否登录
        %>

</body>
</html>