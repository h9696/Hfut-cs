package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.StoreupEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.StoreupVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.StoreupView;


/**
 * 收藏表
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface StoreupService extends IService<StoreupEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<StoreupVO> selectListVO(Wrapper<StoreupEntity> wrapper);
   	
   	StoreupVO selectVO(@Param("ew") Wrapper<StoreupEntity> wrapper);
   	
   	List<StoreupView> selectListView(Wrapper<StoreupEntity> wrapper);
   	
   	StoreupView selectView(@Param("ew") Wrapper<StoreupEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<StoreupEntity> wrapper);
   	
}

