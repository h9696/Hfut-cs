<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/13
  Time: 17:03
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <link rel="stylesheet" type="text/css" href="style/css.css"/>
  <link rel="stylesheet" type="text/css" href="style/aqua.css"/>
  <title>员工工资管理系统――登录页面</title>
</head>
  <SCRIPT Language = "javascript">
    //接下来将执行资料检查
    function isValid()
    {
      //下面的if判断语句将检查是否输入帐号资料
      if (frmLogin.id.value == "")
      {
        window.alert("您必须完成帐号的输入!");
        //显示错误信息
        document.frmLogin.elements(0).focus();
        //将光标移至帐号输入栏
        return  false;
      }

      //下面的if判断语句将检查是否输入帐号密码
      if (frmLogin.password.value == "")
      {
        window.alert("您必须完成密码的输入!");
        //显示错误信息
        document.frmLogin.elements(1).focus();
        //将光标移至密码输入栏
        return  false;  //离开函数
      }
      frmLogin.submit(); //送出表单中的资料
    }
  </SCRIPT>
  <body>
      <%
          // 判断是否有错误信息，如果有则打印
          if (request.getAttribute("err") != null) {
      %>
          <div class="alert alert-danger" >
              <%=request.getAttribute("err")%>
          </div>
      <%
          }
      %>
    <div class="container">
      <form class="login-form" name="frmLogin" action="login_conf.jsp" method="post" onSubmit="return isValid(this);">
          <div style="font-size: 28px;color: slategrey">员工工资管理系统<br>用户登录</div>
          <br>
          <div class="form-group" >
            <span class="mr-2" >账号:</span>
            <input class="form-control" name="id" id="id" type="text" placeholder="请输入ID" />
          </div>
          <br>
          <div class="form-group">
            <span class="mr-2">密码:</span>
            <input class="form-control" name="password" id="password" type="password" placeholder="请输入密码" />
          </div>
          <br>
            <button class="btn btn-primary " type="submit" >
              登录
            </button>
          <br>
            <button class="btn btn-primary btn-ghost" type="reset" >
              重新输入
            </button>
          <br>
      </form>
    </div>

  </body>
</html>
