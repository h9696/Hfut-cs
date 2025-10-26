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
        <link rel="stylesheet" type="text/css" href="style/aqua.css"/>
        <title>员工工资管理系统</title>
    </head>
    <script language="JavaScript">
        function is_valid() {
            var employeeLevel = '<%= session.getAttribute("employeeLevel") %>';
            if (employeeLevel === "管理员") {
                document.getElementById("f1").submit();
                return true;
            } else {
                alert("非管理员无法进行操作");
                return false;
            }
        }
    </script>
    <body>
        <%
            if (session.getAttribute("uname") != null) {
                        // 用户已登陆
        %>	
        <%!
                Connection conn = null;
                PreparedStatement pstmt = null;
                ResultSet rs = null;
        %>
        <%
                // 接收参数
                int id = 0;
                String isUpdate = request.getParameter("id");
                String isUpdateString = null;
                String departmentName = null;
                if(isUpdate != null) {//检测操作是新增数据还是编辑数据,null则为新增数据
                    String sql = "SELECT DepartmentName FROM department WHERE DepartmentID=?";
                    id = Integer.parseInt(request.getParameter("id"));
                    conn = new DBClass().get_con();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setInt(1, id);
                    rs = pstmt.executeQuery();
                    isUpdateString = "编辑部门信息";
                    if (rs.next()) {
                        // 从数据库中取出内容
                        departmentName = rs.getString("DepartmentName");
                    }
                    rs.close();
                    pstmt.close();
                    conn.close();
                }else{
                    isUpdateString = "新增部门信息";
                    departmentName = "";
                }
        %>
                        <div class="container">
                                <form id="f1" action="updateDepartment_do.jsp" method="post" class="updateBox">
                                        <button class="btn btn-primary btn-dashed" style="font-size: 15px" disabled><%=isUpdateString%></button>
                                            <div class="form-group">
                                                部门名称：
                                                <div><input type="text" name="departmentName" value="<%=departmentName%>" style="resize:none;overflow-y:visible;font-size: 17px;color: darkslategray"></div><br><br><br><br><br><br>
                                            </div>
                                            <input type="hidden" name="id" value="<%=id%>">
                                            <button class="btn btn-primary" type="button" onclick="is_valid()">提交</button><br>
                                            <button class="btn btn-primary btn-round" type="button"
                                                    onclick="location.href='list_department.jsp'">
                                                回到列表页
                                            </button>
                                </form>
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