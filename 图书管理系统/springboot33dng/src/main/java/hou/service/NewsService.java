package hou.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import hou.utils.PageUtils;
import hou.entity.NewsEntity;
import java.util.List;
import java.util.Map;
import hou.entity.vo.NewsVO;
import hou.entity.view.NewsView;
import org.apache.ibatis.annotations.Param;


/**
 * 公告信息
 *
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface NewsService extends IService<NewsEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<NewsVO> selectListVO(Wrapper<NewsEntity> wrapper);
   	
   	NewsVO selectVO(@Param("ew") Wrapper<NewsEntity> wrapper);
   	
   	List<NewsView> selectListView(Wrapper<NewsEntity> wrapper);
   	
   	NewsView selectView(@Param("ew") Wrapper<NewsEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<NewsEntity> wrapper);
   	
}

