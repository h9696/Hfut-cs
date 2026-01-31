package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.MessagesEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.MessagesVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.MessagesView;


/**
 * 留言板
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface MessagesService extends IService<MessagesEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<MessagesVO> selectListVO(Wrapper<MessagesEntity> wrapper);
   	
   	MessagesVO selectVO(@Param("ew") Wrapper<MessagesEntity> wrapper);
   	
   	List<MessagesView> selectListView(Wrapper<MessagesEntity> wrapper);
   	
   	MessagesView selectView(@Param("ew") Wrapper<MessagesEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<MessagesEntity> wrapper);
   	
}

