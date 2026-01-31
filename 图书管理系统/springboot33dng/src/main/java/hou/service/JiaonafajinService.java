package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.JiaonafajinEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.JiaonafajinVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.JiaonafajinView;
import org.springframework.stereotype.Service;


/**
 * 缴纳罚金
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface JiaonafajinService extends IService<JiaonafajinEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<JiaonafajinVO> selectListVO(Wrapper<JiaonafajinEntity> wrapper);
   	
   	JiaonafajinVO selectVO(@Param("ew") Wrapper<JiaonafajinEntity> wrapper);
   	
   	List<JiaonafajinView> selectListView(Wrapper<JiaonafajinEntity> wrapper);
   	
   	JiaonafajinView selectView(@Param("ew") Wrapper<JiaonafajinEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<JiaonafajinEntity> wrapper);
   	
}

