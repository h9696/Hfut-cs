
package hou.service;

import java.util.Map;

import com.baomidou.mybatisplus.service.IService;
import hou.entity.ConfigEntity;
import hou.utils.PageUtils;
import org.springframework.stereotype.Service;


/**
 * 系统用户
 */

public interface ConfigService extends IService<ConfigEntity> {
	PageUtils queryPage(Map<String, Object> params);
}
