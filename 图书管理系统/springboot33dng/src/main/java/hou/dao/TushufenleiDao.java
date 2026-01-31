package hou.dao;

import hou.entity.TushufenleiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import hou.entity.view.TushufenleiView;
import hou.entity.vo.TushufenleiVO;
import org.apache.ibatis.annotations.Param;


/**
 * 图书分类
 * 
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface TushufenleiDao extends BaseMapper<TushufenleiEntity> {
	
	List<TushufenleiVO> selectListVO(@Param("ew") Wrapper<TushufenleiEntity> wrapper);
	
	TushufenleiVO selectVO(@Param("ew") Wrapper<TushufenleiEntity> wrapper);
	
	List<TushufenleiView> selectListView(@Param("ew") Wrapper<TushufenleiEntity> wrapper);

	List<TushufenleiView> selectListView(Pagination page,@Param("ew") Wrapper<TushufenleiEntity> wrapper);
	
	TushufenleiView selectView(@Param("ew") Wrapper<TushufenleiEntity> wrapper);
	
}
