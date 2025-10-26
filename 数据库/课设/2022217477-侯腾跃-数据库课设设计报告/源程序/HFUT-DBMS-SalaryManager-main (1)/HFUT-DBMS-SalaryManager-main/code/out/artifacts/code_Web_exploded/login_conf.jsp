<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/13
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
        <title>员工工资管理系统――登录页面</title>
    </head>
    <body>
        <br>
        <%
            Connection conn = null  ;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
        %>
        <%
            // 声明一个boolean变量，用于保存用户是否合法的状态
            boolean flag = false;

            // 接收参数
            String employeeId = request.getParameter("id");   				//用户名
            String password = request.getParameter("password");    //用户密码,转换为sha256后提交到数据库中进行验证
            String employeeLevel = null;
        %>
        <%--登陆检测--%>
        <%
            String sql = "SELECT EmployeeName,EmployeeLevel FROM employee WHERE EmployeeID=? and Password=?";
            conn = new DBClass().get_con();
            try {
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, employeeId);
                pstmt.setString(2, password);
                rs = pstmt.executeQuery();
            }catch (SQLException e) {
                throw new RuntimeException(e);
            }
            try {
                if (rs.next()) {
                    // 用户合法
                    flag = true;
                    // 将用户名保存在session之中
                    try {
                        session.setAttribute("uname", rs.getString("EmployeeName"));  //可用来判断用户是否存在
                    } catch (SQLException e) {
                        throw new RuntimeException(e);
                    }
                    session.setAttribute("id",employeeId);
                    employeeLevel = rs.getString("EmployeeLevel");
                    if(employeeLevel.equals("管理员")){//判断用户类型
                        session.setAttribute("employeeLevel", "管理员");//todo:有时间这里可以加入数据库层级的角色分配从而完善安全性
                    }else{
                        session.setAttribute("employeeLevel", "普通员工");  //可用来判断用户类型
                    }

                } else {
                    // 保存错误信息
                    request.setAttribute("err", "错误的用户名或密码！！！");
                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
            try {
                rs.close();
                pstmt.close();
                conn.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        %>
        <%
            // 跳转
            if (flag) {
                        // 用户合法
        %>
                <jsp:forward page="login_success.jsp"/>
        <%
             } else {
                        // 用户非法
        %>
                <jsp:forward page="login.jsp"/>
        <%
            }
        %>

</body>
</html>