package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.TushuguihaiEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.TushuguihaiVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.TushuguihaiView;


/**
 * 图书归还
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface TushuguihaiService extends IService<TushuguihaiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<TushuguihaiVO> selectListVO(Wrapper<TushuguihaiEntity> wrapper);
   	
   	TushuguihaiVO selectVO(@Param("ew") Wrapper<TushuguihaiEntity> wrapper);
   	
   	List<TushuguihaiView> selectListView(Wrapper<TushuguihaiEntity> wrapper);
   	
   	TushuguihaiView selectView(@Param("ew") Wrapper<TushuguihaiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<TushuguihaiEntity> wrapper);
   	
}

