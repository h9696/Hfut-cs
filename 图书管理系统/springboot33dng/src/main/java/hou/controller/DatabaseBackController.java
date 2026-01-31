package hou.controller;

import hou.utils.DatabaseBackupUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;

@RestController
@RequestMapping("/backup")
public class DatabaseBackController {

    @Autowired
    private DatabaseBackupUtil databaseBackupUtil;

    @PostMapping("/database")
    public String backupDatabase() {
        try {
            databaseBackupUtil.backup();
            return "ok";
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            return "no ok: " + e.getMessage();
        }
    }

    @PostMapping("/restore")
    public String restoreDatabase(@RequestBody String backupFile) {
        try {
            String[] split = backupFile.split("\"");
            backupFile = split[3];
            databaseBackupUtil.restore(backupFile);
            return "ok";
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            return "bad: " + e.getMessage();
        }
    }

}
