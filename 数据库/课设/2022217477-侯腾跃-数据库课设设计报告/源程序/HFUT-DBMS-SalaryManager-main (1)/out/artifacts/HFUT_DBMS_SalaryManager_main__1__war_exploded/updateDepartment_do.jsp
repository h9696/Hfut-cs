<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/1
  Time: 17:03
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="DB.DBClass" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <link rel="stylesheet" type="text/css" href="style/css.css"/>
    <title>员工工资管理系统</title>
</head>
<body>
    <%
        // 进行乱码处理
        request.setCharacterEncoding("UTF-8");
        boolean flag = true;
        String constraintName = null;//控制差错信息
    %>
    <%
        if (session.getAttribute("uname") != null) {
            // 用户已登陆
            int id = 0;
            try {
                id = Integer.parseInt(request.getParameter("id"));
            } catch (Exception e) {
            }
            Connection conn = null;
            PreparedStatement pstmt = null;
            if (id != 0) {// 检查是否是更新页面
                //编辑数据
                // 接收参数
                String departmentName = request.getParameter("departmentName");
                String sql = "UPDATE department SET DepartmentName=? WHERE DepartmentID=?";
                conn = new DBClass().get_con();
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, departmentName);
                pstmt.setInt(2, id);
                try {
                    pstmt.executeUpdate();
                } catch (SQLException e) {
                    flag = false;
                }
                pstmt.close();
            } else {
                //新增数据
                // 接收参数
                String departmentName = request.getParameter("departmentName");
                String sql = "INSERT INTO department(DepartmentName)" +
                        " VALUES (?) ;";
                conn = new DBClass().get_con();
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, departmentName);
                try {
                    pstmt.executeUpdate();
                } catch (SQLException e) {
                    flag = false;
                    constraintName = e.getSQLState();
                } finally {
                    pstmt.close();
                    conn.close();
                }
        }//end 用户已登录
    %>
            <div class="container">
                <div class="infoBox">
                    <%
                    if (flag) {
                        response.setHeader("refresh", "2;URL=list_department.jsp");
                    %>
                    <div>数据提交成功，两秒后跳转到列表页！！！<br><br>
                        <div>如果没有跳转，请按<a href="list_department.jsp">这里</a>！！！</div>
                    </div>
                    <%
                    } else {
                        if (constraintName.equals("23000")) { // 检测到违反唯一约束
                    %>
                            <div>数据插入失败，已存在名字相同的部门！请使用别的名称！<br><br><br>
                                <div><a href="list_department.jsp">取消插入</a></div><br>
                            </div>
                    <%
                         }//end 检测违反唯一约束
                    }//end else
                    %>
                </div>
            </div>
        <%
        } else {
            // 用户未登陆，提示用户登陆，并跳转
            response.setHeader("refresh", "2;URL=login.jsp");
        %>
            <div class="container">
                <div class="infoBox">
                    <div>您还未登陆，请先登陆！！！</div><br>
                    <div>两秒后自动跳转到登陆窗口！！！</div><br>
                    <div>如果没有跳转，请按<a href="login.jsp">这里</a>！！！</div><br>
                </div>
            </div>
    <%
        }
    %>
</body>
</html>
