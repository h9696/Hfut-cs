
<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="DB.DBClass"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="style/css.css"/>
        <title>员工工资管理系统――注册页面</title>
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
                String EmployeeLevel = request.getParameter("EmployeeLevel");
                String EmployeeName = request.getParameter("EmployeeName");
                Date JoinDate = null;
                try {
                    JoinDate = Date.valueOf(request.getParameter("JoinDate"));
                }catch (java.lang.IllegalArgumentException e){
                    flag = false;
                    errInfo = "入职日期不能是空值！";
                }
                int DepartmentID = Integer.parseInt(request.getParameter("DepartmentID"));
                String passwordSHA256 = "";//默认密码：emp123
                String newID = "";//用来记录新用户的id
                String info ="";//注册新用户后将换成提示语
                if (id != 0) {// 检查是否是更新页面
                    PreparedStatement pstmt = null;
                    String sql = "UPDATE employee SET EmployeeName=? ,Password=?,EmployeeLevel=?,DepartmentID=?,JoinDate=? WHERE EmployeeID=?";
                    conn = new DBClass().get_con();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1, EmployeeName);
                    pstmt.setString(2, passwordSHA256);
                    pstmt.setString(3, EmployeeLevel);
                    pstmt.setInt(4, DepartmentID);
                    pstmt.setDate(5, JoinDate);
                    pstmt.setInt(6, id);
                    try {
                        pstmt.executeUpdate();
                    } catch (SQLException e) {
                        flag = false;
                    }
                    pstmt.close();
                } else {
                    //新增数据
                    PreparedStatement pstmt = null;
                    String sql = "INSERT INTO employee(EmployeeName,Password,EmployeeLevel,DepartmentID,JoinDate)" +
                            " VALUES (?,?,?,?,?) ;";
                    conn = new DBClass().get_con();
                    pstmt = conn.prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);//用于返回新用户的ID
                    pstmt.setString(1, EmployeeName);
                    pstmt.setString(2, passwordSHA256);
                    pstmt.setString(3, EmployeeLevel);
                    pstmt.setInt(4, DepartmentID);
                    pstmt.setDate(5, JoinDate);
                    if(EmployeeName == null || EmployeeName.isEmpty()||EmployeeName.equals("null")){
                        flag = false;
                        errInfo = "员工姓名不能是空值！";
                    }else{
                        try {
                        pstmt.executeUpdate();
                        } catch (SQLException e) {
                            flag = false;
                        }//end try
                        ResultSet generatedKeys = pstmt.getGeneratedKeys();
                        if (generatedKeys.next()) {
                            newID = Integer.toString(generatedKeys.getInt(1));
                            info = "新用户的ID是：";
                        }//end if
                    }//end if
                    pstmt.close();
                }
                conn.close();
    %>

        <div class="container">
            <div class="infoBox">
                <%
                    if (flag) {
                %>
                <div>数据提交成功！！！<%=info%><br><br>
                    <div STYLE="color: deeppink"><%=newID%><br><br></div>
                    <div><a href="list_employee.jsp">回到列表页</a></div>
                </div>
                <%
                } else {
                %>
                <div>数据提交失败!<br><br>
                    <div><%=errInfo%><a href="list_employee.jsp"><br><br><br>回到列表页</a></div>
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
</html>