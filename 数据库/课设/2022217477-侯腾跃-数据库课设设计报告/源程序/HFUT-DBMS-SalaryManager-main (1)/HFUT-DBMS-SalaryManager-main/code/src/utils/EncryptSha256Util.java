
package utils;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Base64;
import java.util.Random;

/**
 * 安全加密工具类，使用SHA-256算法并支持盐值和迭代次数
 */
public class EncryptSha256Util {
    private static final String ALGORITHM = "SHA-256";
    private static final int ITERATIONS = 10000; // 迭代次数，增强安全性
    private static final int SALT_LENGTH = 16;  // 盐值长度（字节）

    /**
     * 生成带盐值的安全哈希
     * @param password 明文密码
     */
    public static String generateSecureHash(String password) {
        try {
            // 生成随机盐值
            SecureRandom random = SecureRandom.getInstanceStrong();
            byte[] salt = new byte[SALT_LENGTH];
            random.nextBytes(salt);

            // 计算哈希值
            byte[] hash = hashPassword(password, salt, ITERATIONS);

            // 将盐值和哈希值编码为Base64字符串
            String encodedSalt = Base64.getEncoder().encodeToString(salt);
            String encodedHash = Base64.getEncoder().encodeToString(hash);

            // 返回格式: 盐值:哈希值
            return encodedSalt + ":" + encodedHash;
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("安全哈希算法不可用", e);
        }
    }

    /**
     * 验证密码是否匹配
     * @param password 待验证的明文密码
     * @param storedHash 存储的哈希值（格式为 盐值:哈希值）
     * @return 是否匹配
     */
    public static boolean verifyPassword(String password, String storedHash) {
        try {
            // 分割盐值和哈希值
            String[] parts = storedHash.split(":");
            if (parts.length != 2) {
                return false;
            }

            // 解码盐值和哈希值
            byte[] salt = Base64.getDecoder().decode(parts[0]);
            byte[] hash = Base64.getDecoder().decode(parts[1]);

            // 计算新的哈希值
            byte[] testHash = hashPassword(password, salt, ITERATIONS);

            // 比较哈希值（使用安全的比较方法，防止时序攻击）
            return slowEquals(hash, testHash);
        } catch (Exception e) {
            return false;
        }
    }

    /**
     * 使用指定盐值和迭代次数计算密码哈希
     */
    private static byte[] hashPassword(String password, byte[] salt, int iterations)
            throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance(ALGORITHM);
        digest.reset();
        digest.update(salt);

        byte[] hash = digest.digest(password.getBytes(StandardCharsets.UTF_8));
        for (int i = 0; i < iterations - 1; i++) {
            digest.reset();
            hash = digest.digest(hash);
        }
        return hash;
    }

    /**
     * 缓慢比较两个字节数组，防止时序攻击
     */
    private static boolean slowEquals(byte[] a, byte[] b) {
        int diff = a.length ^ b.length;
        for (int i = 0; i < a.length && i < b.length; i++) {
            diff |= a[i] ^ b[i];
        }
        return diff == 0;
    }

    /**
     * 生成随机密码
     * @param length 密码长度
     * @return 随机密码
     */
    public static String generateRandomPassword(int length) {
        String chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
        Random random = new SecureRandom();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < length; i++) {
            int index = random.nextInt(chars.length());
            sb.append(chars.charAt(index));
        }

        return sb.toString();
    }
}