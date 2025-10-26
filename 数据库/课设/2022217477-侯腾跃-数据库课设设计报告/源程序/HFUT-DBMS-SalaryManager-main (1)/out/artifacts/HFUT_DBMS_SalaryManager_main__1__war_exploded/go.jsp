<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/13
  Time: 18:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8"%>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<link rel="stylesheet" type="text/css" href="style/css.css"/>
		<title>员工工资管理系统――退出</title>
	</head>
	<body>
		<%
			// 进行乱码处理
			request.setCharacterEncoding("UTF-8") ;
		%>
		<%   //退出系统的操作
			if(session.getAttribute("uname")!=null)
			{
				session.setAttribute("uname","null") ;
				session.invalidate();
		%>
				<div class="container">
					<div class="infoBox">
						您已经成功退出，若要进行操作<br>
						请重新登录<br>
						如果没有跳转，请按<a href="login.jsp">这里</a><br>
					</div>
				</div>
		<%
			}
			else
			{
		%>
				<div class="container">
					<div class="infoBox">
						您已经成功退出，若要进行操作<br>
						请重新登录<br>
						如果没有跳转，请按<a href="login.jsp">这里</a><br>
					</div>
				</div>
		<%
			}
		%>

	</body>
</html>