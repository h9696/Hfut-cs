package hou.utils;

import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;
import java.io.IOException;

@EnableScheduling
@Component
public class ScheduledBackup {
    private final DatabaseBackupUtil backupUtil;

    public ScheduledBackup(DatabaseBackupUtil backupUtil) {
        this.backupUtil = backupUtil;
    }

    // 每天凌晨 2 点备份（cron 表达式）
    @Scheduled(cron = "0 0 2 * * *")
    public void scheduledBackup() {
        try {
            backupUtil.backup();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}