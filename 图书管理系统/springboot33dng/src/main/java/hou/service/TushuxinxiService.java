package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.TushuxinxiEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.TushuxinxiVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.TushuxinxiView;


/**
 * 图书信息
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface TushuxinxiService extends IService<TushuxinxiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<TushuxinxiVO> selectListVO(Wrapper<TushuxinxiEntity> wrapper);
   	
   	TushuxinxiVO selectVO(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
   	
   	List<TushuxinxiView> selectListView(Wrapper<TushuxinxiEntity> wrapper);
   	
   	TushuxinxiView selectView(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<TushuxinxiEntity> wrapper);
   	
}

