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
            String errInfo="";
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
                // 接收参数
                double BaseSalary = Double.parseDouble(request.getParameter("BaseSalary"));
                Date SalaryPaymentDate = null;
                try {
                    SalaryPaymentDate = Date.valueOf(request.getParameter("SalaryPaymentDate"));
                }catch (java.lang.IllegalArgumentException e){
                    flag = false;
                    errInfo = "发放日期不能是空值！";
                }
                int EmployeeID = Integer.parseInt(request.getParameter("EmployeeID"));
                if (id != 0) {// 检查是否是更新页面
                    //编辑数据
                    PreparedStatement pstmt = null;
                    String sql = "UPDATE salary SET BaseSalary=? , EmployeeID=? , SalaryPaymentDate=? WHERE SalaryID=?";
                    conn = new DBClass().get_con();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setDouble(1, BaseSalary);
                    pstmt.setInt(2, EmployeeID);
                    pstmt.setDate(3, SalaryPaymentDate);
                    pstmt.setInt(4, id);
                    try {
                        pstmt.executeUpdate();
                    } catch (SQLException e) {
                        flag = false;
                    }
                    pstmt.close();
                } else {
                    //新增数据
                    PreparedStatement pstmt = null;
                    String sql = "INSERT INTO salary(BaseSalary,EmployeeID,SalaryPaymentDate)" +
                            " VALUES (?,?,?) ;";
                    conn = new DBClass().get_con();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setDouble(1, BaseSalary);
                    pstmt.setInt(2, EmployeeID);
                    pstmt.setDate(3, SalaryPaymentDate);
                    try {
                        pstmt.executeUpdate();
                    } catch (SQLException e) {
                        flag = false;
                    }
                    pstmt.close();
                }
                conn.close();
    %>

                <div class="container">
                    <div class="infoBox">
                        <%
                        if (flag) {
                            response.setHeader("refresh", "2;URL=list_salary.jsp");
                        %>
                        <div>数据提交成功，两秒后跳转到列表页！！！<br><br>
                            <div>如果没有跳转，请按<a href="list_salary.jsp">这里</a>！！！</div>
                        </div>
                        <%
                        } else {
                        %>
                        <div>数据提交失败!<br><br>
                            <div><%=errInfo%><a href="list_salary.jsp"><br><br><br>回到列表页</a></div>
                        </div>
                        <%
                            }
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
