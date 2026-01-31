package hou.dao;

import hou.entity.MessagesEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import hou.entity.view.MessagesView;
import hou.entity.vo.MessagesVO;
import org.apache.ibatis.annotations.Param;


/**
 * 留言板
 * 
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
public interface MessagesDao extends BaseMapper<MessagesEntity> {
	
	List<MessagesVO> selectListVO(@Param("ew") Wrapper<MessagesEntity> wrapper);
	
	MessagesVO selectVO(@Param("ew") Wrapper<MessagesEntity> wrapper);
	
	List<MessagesView> selectListView(@Param("ew") Wrapper<MessagesEntity> wrapper);

	List<MessagesView> selectListView(Pagination page,@Param("ew") Wrapper<MessagesEntity> wrapper);
	
	MessagesView selectView(@Param("ew") Wrapper<MessagesEntity> wrapper);
	
}
