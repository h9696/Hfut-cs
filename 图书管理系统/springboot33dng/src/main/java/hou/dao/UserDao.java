
package hou.dao;

import java.util.List;

import hou.entity.UserEntity;
import org.apache.ibatis.annotations.Param;

import com.baomidou.mybatisplus.mapper.BaseMapper;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

/**
 * 用户
 */
public interface UserDao extends BaseMapper<UserEntity> {
	
	List<UserEntity> selectListView(@Param("ew") Wrapper<UserEntity> wrapper);

	List<UserEntity> selectListView(Pagination page,@Param("ew") Wrapper<UserEntity> wrapper);
	
}
