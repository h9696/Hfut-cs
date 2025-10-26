<%--
  Created by IntelliJ IDEA.
  User: Root
  Date: 2023/5/13
  Time: 18:09
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="DB.DBClass"%>
<%@ page import="java.util.Map" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.HashMap" %>


<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <link rel="stylesheet" type="text/css" href="style/css.css"/>
    <link rel="stylesheet" type="text/css" href="style/aqua.css"/>
    <title>员工工资管理系统―列表</title>
</head>
<body>
        <br>
        <%
        // 编码转换
        request.setCharacterEncoding("UTF-8");
        int pageSize = 10; // 每页显示的条数
        int totalRows = 0; //数据总条数
        int currentPage = 0; // 当前页码
        int totalPages = 0;//总页码数
        ArrayList<Map<String, Object>> records = null;
        if (session.getAttribute("uname") != null) {
            // 用户已登陆
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            int i = 0;// 如果有内容，则修改变量i，如果没有，则根据i的值进行无内容提示
            String sql = null;
            String sqlCount = null;
            String keyword = request.getParameter("keyword");//接受输入的搜索关键词
            String strPage = request.getParameter("CorrespondPages");//通过接受页面之前传递的参数来确定现在应该显示的页码
            conn = new DBClass().get_con();
            if (keyword != null) {
                // 有查询条件
                sql = "SELECT AllowanceView.* , EmployeeView.EmployeeName " +
                        "FROM AllowanceView JOIN EmployeeView " +
                        "ON AllowanceView.EmployeeID = EmployeeView.EmployeeID " +
                        "WHERE AllowanceID like ? or AllowancePaymentDate like ? or EmployeeName like ? " +
                        "LIMIT ?,?;";
                sqlCount = "SELECT COUNT(*) AS totalRows " +
                        "FROM AllowanceView JOIN EmployeeView " +
                        "ON AllowanceView.EmployeeID = EmployeeView.EmployeeID " +
                        "WHERE AllowanceID like ? or AllowancePaymentDate like ? or EmployeeName like ?;";//统计搜索结果的条数
            } else {
                // 没有查询条件
                sql = "SELECT AllowanceView.* , EmployeeView.EmployeeName " +
                        "FROM AllowanceView JOIN EmployeeView " +
                        "ON AllowanceView.EmployeeID = EmployeeView.EmployeeID " +
                        "order by AllowanceID " +
                        "LIMIT ?,?;";
                // 获取数据总条数和总页数
                sqlCount = "SELECT COUNT(*) AS totalRows FROM Allowance;";
            }
            //处理数据条数和页码数量
            pstmt = conn.prepareStatement(sqlCount);
            if (keyword != null) {
                pstmt.setString(1, "%" + keyword + "%");
                pstmt.setString(2, "%" + keyword + "%");
                pstmt.setString(3, "%" + keyword + "%");
            }
            rs = pstmt.executeQuery();
            if (rs.next()) {
                totalRows = rs.getInt("totalRows");
            }
            totalPages = (int)Math.ceil(totalRows / (pageSize*1.0));//页码数向上取整
            if (strPage == null) {
                currentPage = 1;//默认页码为1
            } else {
                try{
                    currentPage = java.lang.Integer.parseInt(strPage);
                }catch(Exception e){
                    currentPage = 1;//防止出错后无法加载页面的情况
                }
                if (currentPage < 1){
                    currentPage = 1;//防止点击上一页后出错无法加载页面的情况
                }
                if (currentPage > totalPages){
                    currentPage = totalPages;//防止点击下一页后出错无法加载页面的情况
                }
            }
            //处理展示数据
            pstmt = conn.prepareStatement(sql);
            if (keyword != null) {
                // 存在查询条件
                pstmt.setString(1, "%" + keyword + "%");
                pstmt.setString(2, "%" + keyword + "%");
                pstmt.setString(3, "%" + keyword + "%");
                pstmt.setInt(4, (currentPage-1) * pageSize);
                pstmt.setInt(5, pageSize);
            }else {
                pstmt.setInt(1, (currentPage-1) * pageSize);
                pstmt.setInt(2, pageSize);
            }
            rs = pstmt.executeQuery();
        %>
        <div class="container2">
            <div class="form-wrapper">
                <form action="list_allowance.jsp" method="POST">
                    <div class="input-group">
                        <input class="form-control" type="text" placeholder="输入搜索关键词" name="keyword" />
                        <button class="btn btn-primary" type="submit" id="searchButton"><i class="search-icon" ></i></button>
                    </div>
                </form>
                <div class="button-wrapper">
                    <button class="btn btn-primary" onclick="location.href='updateAllowance.jsp'">
                        <div class="inline-flex items-center space-x-2">
                            <i class="plus-icon"></i>
                            <div>发放津贴</div>
                        </div>
                    </button>
                </div>
                <div class="button-wrapper">
                    <button class="btn btn-danger" onclick="location.href='go.jsp'">
                        <div class="inline-flex items-center space-x-2">
                            退出登录
                        </div>
                    </button>
                </div>　
            </div>
        <%
            if (session.getAttribute("employeeLevel").equals("普通员工")) {
        %>
            <div class="nav-wrapper">
                <ul class="nav">
                    <li class="nav-item"><a class="nav-link" href="list_employee.jsp" style="font-size:15px;">员工表</a></li>
                    <li class="nav-item"><a class="nav-link" href="list_department.jsp" style="font-size:15px;">部门表</a></li>
                    <li class="nav-item"><a class="nav-link" href="list_salary.jsp" style="font-size:15px;">工资表</a></li>
                    <li class="nav-item"><a class="nav-link" href="list_allowance.jsp" style="font-size:15px;">津贴表</a></li>
                    <li class="nav-item"><a class="nav-link" href="list_OTsalary.jsp" style="font-size:15px;">加班费表</a></li>
                    <li class="nav-item"><a class="nav-link" href="list_deduction.jsp" style="font-size:15px;">代扣款项表</a></li>
                </ul>
            </div>
            <div class="table-wrapper">
                <table id="listNodes" width="1000px" >
                    <tr>
                        <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">津贴ID</th>
                        <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">收款员工</th>
                        <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">津贴金额</th>
                        <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">发放日期</th>
                    </tr>
                    <%
                        while (rs.next()) {//todo:简化普通员工的代码，删除掉搜索功能
                            i++;
                            // 进行循环打印，打印出所有的内容，以表格形式
                            // 从数据库中取出内容
                            int allowanceID = rs.getInt("AllowanceID");
                            String employeeName = rs.getString("EmployeeName");
                            double allowanceAmount = rs.getDouble("AllowanceAmount");
                            Date allowancePaymentDate = rs.getDate("AllowancePaymentDate");
                            if (keyword != null) {
                                // 需要将匹配的数据字符变红
                                employeeName = employeeName.replaceAll(keyword, "<font color=\"deeppink\">" + keyword + "</font>");
                            }
                    %>
                    <tr>
                        <th><%=allowanceID%></th>
                        <th><%=employeeName %></th>
                        <th><%=allowanceAmount %></th>
                        <th><%=allowancePaymentDate%></th>
                    </tr>

                    <%
                        }
                        // 判断i的值是否改变，如果改变，则表示有内容，反之，无内容
                        if (i == 0) {
                            // 进行提示
                    %>
                    <tr>
                        <td>没有任何内容！！！</td>
                    </tr>
                    <%
                        }
                    %>
                </table>
                <br>
                <form  method="POST" action="list_allowance.jsp">
                    <div class="page-wrapper">　
                        <div class="button-wrapper">
                            <% if (currentPage > 1) { %>
                            <button type="submit" name="CorrespondPages" class="btn btn-primary btn-round" value="<%=(currentPage<1)?currentPage:(currentPage-1) %>">
                                前一页
                            </button>
                            <% } %>
                        </div>
                        <div class="button-wrapper">
                            <button class="btn btn-primary  btn-dashed ">
                                第 <%=currentPage%> 页 / 共 <%=totalPages%> 页
                            </button>
                        </div>
                        <div class="button-wrapper">
                            <% if (currentPage < totalPages) { %>
                            <button type="submit" name="CorrespondPages" class="btn btn-primary btn-round" value="<%=(currentPage>=totalPages)?totalPages:(currentPage+1)%>">
                                后一页
                            </button>
                            <% } %>
                        </div>
                    </div>
                </form>
            </div>
            <%
                rs.close();
                pstmt.close();
                conn.close();
            } else {
                    //管理员页面

            %>
                <div class="nav-wrapper">
                    <ul class="nav">
                        <li class="nav-item"><a class="nav-link" href="list_employee.jsp" style="font-size:15px;">员工表</a></li>
                        <li class="nav-item"><a class="nav-link" href="list_department.jsp" style="font-size:15px;">部门表</a></li>
                        <li class="nav-item"><a class="nav-link" href="list_salary.jsp" style="font-size:15px;">工资表</a></li>
                        <li class="nav-item"><a class="nav-link" href="list_allowance.jsp" style="font-size:15px;">津贴表</a></li>
                        <li class="nav-item"><a class="nav-link" href="list_OTsalary.jsp" style="font-size:15px;">加班费表</a></li>
                        <li class="nav-item"><a class="nav-link" href="list_deduction.jsp" style="font-size:15px;">代扣款项表</a></li>
                    </ul>
                </div>
                <div class="table-wrapper">
                    <table id="listNodes" width="1000px" >
                        <tr>
                            <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">津贴ID</th>
                            <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">收款员工</th>
                            <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">津贴金额</th>
                            <th width="6%"style="font-size: 18px;color: rgb(204,211,252);">发放日期</th>
                            <th width="5%"style="font-size: 18px;color: rgb(204,211,252);">编辑</th>
                            <th width="5%"style="font-size: 18px;color: rgb(204,211,252);">删除</th>
                        </tr>
                        <%
                            while (rs.next()) {//todo:简化普通员工的代码，删除掉搜索功能
                                i++;
                                // 进行循环打印，打印出所有的内容，以表格形式
                                // 从数据库中取出内容
                                int allowanceID = rs.getInt("AllowanceID");
                                String employeeName = rs.getString("EmployeeName");
                                double allowanceAmount = rs.getDouble("AllowanceAmount");
                                Date allowancePaymentDate = rs.getDate("AllowancePaymentDate");
                                if (keyword != null) {
                                    // 需要将匹配的数据字符变红
                                    employeeName = employeeName.replaceAll(keyword, "<font color=\"deeppink\">" + keyword + "</font>");
                                }
                        %>
                        <tr>
                                <th><%=allowanceID%></th>
                                <th><%=employeeName %></th>
                                <th><%=allowanceAmount %></th>
                                <th><%=allowancePaymentDate%></th>
                                <th><a href="updateAllowance.jsp?id=<%=allowanceID%>" style="font-size: 15px;">编辑</a></th>
                                <th><a href="delete_conf.jsp?id=<%=allowanceID%>&table=allowance&keyName=allowanceID" style="font-size: 15px;">删除</a></th>
                        </tr>

                        <%
                            }
                            // 判断i的值是否改变，如果改变，则表示有内容，反之，无内容
                            if (i == 0) {
                                // 进行提示
                        %>
                        <tr>
                            <td>没有任何内容！！！</td>
                        </tr>
                        <%
                            }
                        %>
                    </table>
                    <br>
                    <form  method="POST" action="list_allowance.jsp">
                        <div class="page-wrapper">　
                            <div class="button-wrapper">
                                <% if (currentPage > 1) { %>
                                <button type="submit" name="CorrespondPages" class="btn btn-primary btn-round" value="<%=(currentPage<1)?currentPage:(currentPage-1) %>">
                                    前一页
                                </button>
                                <% } %>
                            </div>
                            <div class="button-wrapper">
                                <button class="btn btn-primary  btn-dashed ">
                                    第 <%=currentPage%> 页 / 共 <%=totalPages%> 页
                                </button>
                            </div>
                            <div class="button-wrapper">
                                <% if (currentPage < totalPages) { %>
                                <button type="submit" name="CorrespondPages" class="btn btn-primary btn-round" value="<%=(currentPage>=totalPages)?totalPages:(currentPage+1)%>">
                                    后一页
                                </button>
                                <% } %>
                            </div>
                        </div>
                    </form>
                </div>
                <%
                    rs.close();
                    pstmt.close();
                    conn.close();
                }
            %>
            <%
        } else {
                // 用户未登录，提示用户登录，并跳转
                response.setHeader("refresh", "2;URL=login.jsp");
            %>
            <div class="container">
                <div class="infoBox">
                    <div>您还未登陆，请先登陆！！！</div><br>
                    <div>两秒后自动跳转到登陆窗口！！！</div><br>
                    <div>如果没有跳转，请按<a href="login.jsp">这里</a>！！！</div><br>
                </div>
            </div>
            <hr>
        <%
        }
        %>
        <hr>
</body>
</html>