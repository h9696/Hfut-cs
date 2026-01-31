package hou.dao;

import hou.entity.TushuxinxiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import hou.entity.view.TushuxinxiView;
import hou.entity.vo.TushuxinxiVO;
import org.apache.ibatis.annotations.Param;


/**
 * 图书信息
 * 
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface TushuxinxiDao extends BaseMapper<TushuxinxiEntity> {
	
	List<TushuxinxiVO> selectListVO(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
	
	TushuxinxiVO selectVO(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
	
	List<TushuxinxiView> selectListView(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);

	List<TushuxinxiView> selectListView(Pagination page,@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
	
	TushuxinxiView selectView(@Param("ew") Wrapper<TushuxinxiEntity> wrapper);
	
}
