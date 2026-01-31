package hou.utils;

import org.springframework.stereotype.Component;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

@Component
public class DatabaseBackupUtil {
    private static final String DB_USER = "root";
    private static final String DB_NAME = "springboot33dng";
    private static final String BACKUP_DIR = "D:/data/sql"; // 备份文件存储路径

    // 备份数据库
    public void backup() throws IOException, InterruptedException {
        // 确保备份目录存在
        File dir = new File(BACKUP_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }

        String timestamp = System.currentTimeMillis() + "";
        String backupFile = BACKUP_DIR + "/studentms_backup_" + timestamp + ".sql";

        // 构建命令参数列表（关键修改）
        List<String> command = new ArrayList<>();

        // 根据操作系统选择命令执行方式
        if (System.getProperty("os.name").toLowerCase().contains("windows")) {
            command.add("cmd");
            command.add("/c");
        }

        // 正确的参数顺序和格式
        command.add("mysqldump");
        command.add("--defaults-extra-file=" + getMyCnfPath()); // 修复参数格式
        command.add("--user=" + DB_USER);
        command.add(DB_NAME);

        // 打印完整命令用于调试
        System.out.println("执行命令: " + String.join(" ", command));

        // 使用 ProcessBuilder 执行命令，并将输出重定向到文件
        ProcessBuilder pb = new ProcessBuilder(command);
        pb.redirectOutput(new File(backupFile)); // 正确的输出重定向方式
        pb.redirectErrorStream(true); // 合并错误流和输出流

        Process process = pb.start();

        // 输出命令执行日志
        try (BufferedReader br = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println("mysqldump: " + line);
            }
        }

        int exitCode = process.waitFor();
        if (exitCode == 0) {
            System.out.println("备份成功：" + backupFile);
        } else {
            throw new RuntimeException("备份失败，错误码：" + exitCode);
        }
    }

    public static boolean backup(String dbUser, String dbName, String filePath) {
        try {
            ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "mysqldump", "--defaults-extra-file=C:/Users/Hty/.my.cnf", "--user=" + dbUser, dbName);
            pb.redirectOutput(new File(filePath));
            Process process = pb.start();
            int exitCode = process.waitFor();
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String line;
            while ((line = errorReader.readLine()) != null) {
                System.err.println("Backup Error: " + line); // Added detailed error output
            }
            return exitCode == 0;
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("备份失败，错误码：" + e.getMessage());
        }
    }

    // 恢复数据库
    public void restore(String backupFile) throws IOException, InterruptedException {
        // 构建命令参数列表
        List<String> command = new ArrayList<>();

        if (System.getProperty("os.name").toLowerCase().contains("windows")) {
            command.add("cmd");
            command.add("/c");
        }

        // 正确的参数顺序和格式
        command.add("mysql");
        command.add("--defaults-extra-file=" + getMyCnfPath());
        command.add("--user=" + DB_USER);
        command.add(DB_NAME);

        // 打印完整命令用于调试
        System.out.println("执行命令: " + String.join(" ", command));

        // 使用 ProcessBuilder 执行命令，并从文件读取输入
        ProcessBuilder pb = new ProcessBuilder(command);
        String filePath = BACKUP_DIR+"/"+backupFile;
        System.out.println("备份文件路径: " + filePath);
        File file = new File(filePath);
        pb.redirectInput(file); // 正确的输入重定向方式
        pb.redirectErrorStream(true);

        Process process = pb.start();

        // 输出命令执行日志
        try (BufferedReader br = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println("mysql: " + line);
            }
        }

        int exitCode = process.waitFor();
        if (exitCode == 0) {
            System.out.println("恢复成功：" + backupFile);
        } else {
            throw new RuntimeException("恢复失败，错误码：" + exitCode);
        }
    }

    // 获取 MySQL 配置文件路径
    private String getMyCnfPath() {
        String os = System.getProperty("os.name").toLowerCase();
        if (os.contains("windows")) {
            return "C:/Users/" + System.getProperty("user.name") + "/.my.cnf";
        } else {
            return "/home/" + System.getProperty("user.name") + "/.my.cnf";
        }
    }

    // 创建 MySQL 配置文件（首次运行时调用）
    public void createMyCnfFile() throws IOException {
        String myCnfPath = getMyCnfPath();
        File myCnf = new File(myCnfPath);

        try (FileWriter fw = new FileWriter(myCnf);
             BufferedWriter bw = new BufferedWriter(fw)) {
            bw.write("[client]");
            bw.newLine();
            bw.write("user=" + DB_USER);
            bw.newLine();
            bw.write("password=253619"); // 这里使用你的密码
            bw.newLine();
        }

        // 设置文件权限（Windows 下可能需要手动设置）
        if (!System.getProperty("os.name").toLowerCase().contains("windows")) {
            try {
                Process process = Runtime.getRuntime().exec("chmod 600 " + myCnfPath);
                process.waitFor();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}