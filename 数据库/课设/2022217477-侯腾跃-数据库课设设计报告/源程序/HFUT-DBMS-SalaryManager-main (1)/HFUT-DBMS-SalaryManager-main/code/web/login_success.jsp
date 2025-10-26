
<%@ page contentType="text/html;charset=UTF-8"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="style/css.css"/>
        <title>员工工资管理系统――登录页面</title>
    </head>
    <body >
        <br>
        <%
            if (session.getAttribute("uname") != null) {
                        // 用户已登陆
        %>
        <div class="container">
            <div class="infoBox">
                <div>登录成功</div>
                <div>欢迎<font color="red" size="12">
                    <%=session.getAttribute("uname")%>
                    <%="["%>
                    <%=session.getAttribute("employeeLevel")%>
                    <%="]"%>
                    </font>欢迎光临员工工资管理系统</div>
                <div>两秒后跳转到主界面</div>
                <%		response.setHeader("refresh", "2;URL=list_employee.jsp");
                %>
                <div>如果未跳转请点击<a href="list_employee.jsp">这里</a></div>
                <%
                } else {
                    // 用户未登陆，提示用户登陆，并跳转
                    response.setHeader("refresh", "2;URL=login.jsp");
                %>
                您还未登陆，请先登陆！！！<br>
                两秒后自动跳转到登陆窗口！！！<br>
                如果没有跳转，请按<a href="login.jsp">这里</a>！！！<br>
                <%
                    }
                %>
            </div>
        </div>
</body>
</html>