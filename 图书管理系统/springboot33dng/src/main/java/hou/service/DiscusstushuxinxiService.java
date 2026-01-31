package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.DiscusstushuxinxiEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.DiscusstushuxinxiVO;
import org.apache.ibatis.annotations.Param;
import hou.entity.view.DiscusstushuxinxiView;
import org.springframework.stereotype.Service;


/**
 * 图书信息评论表
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */

public interface DiscusstushuxinxiService extends IService<DiscusstushuxinxiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<DiscusstushuxinxiVO> selectListVO(Wrapper<DiscusstushuxinxiEntity> wrapper);
   	
   	DiscusstushuxinxiVO selectVO(@Param("ew") Wrapper<DiscusstushuxinxiEntity> wrapper);
   	
   	List<DiscusstushuxinxiView> selectListView(Wrapper<DiscusstushuxinxiEntity> wrapper);
   	
   	DiscusstushuxinxiView selectView(@Param("ew") Wrapper<DiscusstushuxinxiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<DiscusstushuxinxiEntity> wrapper);
   	
}

