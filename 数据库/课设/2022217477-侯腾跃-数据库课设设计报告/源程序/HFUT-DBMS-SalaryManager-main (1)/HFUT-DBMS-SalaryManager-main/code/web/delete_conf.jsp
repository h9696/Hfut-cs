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
            // 接收参数
            int id = 0;
            String keyName = null;
            String table = null;
            id = Integer.parseInt(request.getParameter("id"));
            table = request.getParameter("table");
            keyName = request.getParameter("keyName");
        %>
            <div class="container">
                <div class="infoBox">
                    <div>确定要删除该数据吗，一旦确认操作则数据将无法恢复！<br><br><br>
                        <div><a href="list_employee.jsp">取消删除</a></div><br>
                        <div><a href="delete_do.jsp?id=<%=id%>&table=<%=table%>&keyName=<%=keyName%>" style="color: deeppink">确认删除</a></div>
                    </div>
                </div>
            </div>
        <%
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
            }
        %>

</body>
</html>