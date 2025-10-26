<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/13
  Time: 17:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="DB.DBClass"%>
<script type="text/javascript" src="laydate/laydate.js"></script>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="style/css.css"/>
        <link rel="stylesheet" type="text/css" href="style/aqua.css"/>
        <title>员工工资管理系统――注册新员工页面</title>
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
        <%
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            // 接收参数
            int id = 0;
            String isUpdate = request.getParameter("id");
            String isUpdateString = null;
            String DepartmentName = null;
            Date JoinDate = null;
            String EmployeeName = null;
            conn = new DBClass().get_con();
            if(isUpdate != null) {//检测操作是新增数据还是编辑数据,null则为新增数据
                String sql = "SELECT employee.* , department.DepartmentName " +
                        "FROM employee JOIN department " +
                        "on employee.DepartmentID = department.DepartmentID WHERE EmployeeID=?";
                id = Integer.parseInt(request.getParameter("id"));
                pstmt = conn.prepareStatement(sql);
                pstmt.setInt(1, id);
                rs = pstmt.executeQuery();
                isUpdateString = "修改员工信息";
                if (rs.next()) {
                    // 从数据库中取出内容
                    JoinDate = rs.getDate("JoinDate");
                    DepartmentName = rs.getString("DepartmentName");
                    EmployeeName = rs.getString("EmployeeName");
                }
            }else{
                EmployeeName = "";
                isUpdateString = "注册新员工";
                DepartmentName = "";
            }
            String sql = "SELECT DepartmentID, DepartmentName FROM Department " ;//用来展示可以发放工资的员工
            pstmt = conn.prepareStatement(sql);
            rs = pstmt.executeQuery();
        %>
            <div class="container">
                <form id="f1" action="signInInsert_do.jsp" method="post" class="signInBox">
                    <button class="btn btn-primary btn-dashed" style="font-size: 15px" disabled><%=isUpdateString%></button><br>
                    <div class="radio-group">
                        <div>权限：</div>
                        <div>
                            <input type="radio" class="form-check-input" value="管理员" name="EmployeeLevel">
                            <label class="form-check-label">管理员</label>
                        </div>
                        <div>
                            <input type="radio" class="form-check-input" value="普通员工" name="EmployeeLevel" checked>
                            <label class="form-check-label">普通员工</label>
                        </div>
                    </div>
                    <div class="form-group">
                        <label>员工姓名：</label>
                        <input type="text" name="EmployeeName" value="<%=EmployeeName%>">
                    </div>
                    <div class="form-group">
                        <label>入职时间：</label>
                        <input type="text" id="date" readonly name="JoinDate" value="<%=JoinDate%>">
                        <script>
                            laydate.render({
                                elem: '#date',
                                trigger: 'click'
                            });
                        </script>
                    </div>
                    <div class="form-group">
                        <label>员工所属部门：</label>
                        <select name="DepartmentID">
                            <% while (rs.next()) { %>
                            <option value="<%= rs.getString("DepartmentID") %>" <%= rs.getString("DepartmentName").equals(DepartmentName) ? "selected='selected'" : "" %>>
                                <%= rs.getString("DepartmentName") %>
                            </option>
                            <% } %>
                        </select>
                    </div>
                    <div style="font-size: 13px;color: deeppink">员工ID将会在注册后自动生成<br>默认密码为 2023HFUT</div>
                    <input type="hidden" name="id" value="<%=id%>">
                    <div class="button-group">
                        <button class="btn btn-success" type="button" onclick="is_valid()">提交</button>
                        <button class="btn btn-primary btn-ghost" type="reset">清空</button>
                    </div>
                    <button class="btn btn-primary btn-round" type="button" onclick="location.href='list_employee.jsp'">回到列表页</button>
                </form>
            </div>
        <%
            rs.close();
            pstmt.close();
            conn.close();
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