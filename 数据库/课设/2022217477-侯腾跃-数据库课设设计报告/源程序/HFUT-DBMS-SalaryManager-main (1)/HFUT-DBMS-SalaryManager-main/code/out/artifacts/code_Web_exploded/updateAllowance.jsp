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
<script type="text/javascript" src="laydate/laydate.js"></script>
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
                String EmployeeName = null;
                double AllowanceAmount = 0;
                Date AllowancePaymentDate = null;
                conn = new DBClass().get_con();
                if(isUpdate != null) {//检测操作是新增数据还是编辑数据,null则为新增数据
                    String sql = "SELECT allowance.* , employee.EmployeeName " +
                            "FROM allowance JOIN employee " +
                            "on allowance.EmployeeID = employee.EmployeeID WHERE AllowanceID=?";
                    id = Integer.parseInt(request.getParameter("id"));
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setInt(1, id);
                    rs = pstmt.executeQuery();
                    isUpdateString = "编辑津贴信息";
                    if (rs.next()) {
                        // 从数据库中取出内容
                        AllowancePaymentDate = rs.getDate("AllowancePaymentDate");
                        AllowanceAmount = rs.getDouble("AllowanceAmount");
                        EmployeeName = rs.getString("EmployeeName");
                    }
                }else{
                    isUpdateString = "新增津贴信息";
                    AllowanceAmount = 0;
                }
                String sql = "SELECT EmployeeName, EmployeeID FROM employee " ;//用来展示可以发放工资的员工
                pstmt = conn.prepareStatement(sql);
                rs = pstmt.executeQuery();
        %>
                        <div class="container">
                                <form id="f1" action="updateAllowance_do.jsp" method="post" class="updateBox">
                                        <button class="btn btn-primary btn-dashed" style="font-size: 15px" disabled><%=isUpdateString%></button><br>
                                        <div class="form-group">
                                            发放津贴（元）:
                                            <div><input type="text" name="AllowanceAmount" value="<%=AllowanceAmount%>" style="width:140px;overflow-y:visible;font-size: 17px;color: darkslategray"></div><br>
                                        </div>
                                        <div class="form-group">
                                            收款员工:
                                            <select name="EmployeeID">
                                                <% while (rs.next()) { %>
                                                <option value="<%= rs.getString("EmployeeID") %>" <%= rs.getString("EmployeeName").equals(EmployeeName) ? "selected='selected'" : "" %>>
                                                    <%= rs.getString("EmployeeName") %>
                                                </option>
                                                <% } %>
                                            </select>
                                        </div>
                                        <div class="form-group">
                                            发放日期:
                                            <div><input type="text" name="AllowancePaymentDate" value="<%=AllowancePaymentDate%>"
                                                        id="date" readonly style="resize:none;overflow-y:visible;font-size: 17px;color: darkslategray"></div>
                                            <script>
                                                laydate.render({
                                                    elem: '#date',
                                                    trigger: 'click'
                                                });
                                            </script>
                                        </div>
                                        <br><br>
                                        <input type="hidden" name="id" value="<%=id%>">
                                        <button class="btn btn-primary" type="button" onclick="is_valid()">提交</button><br>
                                        <button class="btn btn-primary btn-round" type="button"
                                                onclick="location.href='list_allowance.jsp'">
                                            回到列表页
                                        </button>
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