package hou.service.impl;

import hou.service.JiaonafajinService;
import org.springframework.stereotype.Service;
import java.util.Map;
import java.util.List;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.plugins.Page;
import com.baomidou.mybatisplus.service.impl.ServiceImpl;
import hou.utils.PageUtils;
import hou.utils.Query;


import hou.dao.JiaonafajinDao;
import hou.entity.JiaonafajinEntity;
import hou.entity.vo.JiaonafajinVO;
import hou.entity.view.JiaonafajinView;

@Service("jiaonafajinService")
public class JiaonafajinServiceImpl extends ServiceImpl<JiaonafajinDao, JiaonafajinEntity> implements JiaonafajinService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<JiaonafajinEntity> page = this.selectPage(
                new Query<JiaonafajinEntity>(params).getPage(),
                new EntityWrapper<JiaonafajinEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<JiaonafajinEntity> wrapper) {
		  Page<JiaonafajinView> page =new Query<JiaonafajinView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<JiaonafajinVO> selectListVO(Wrapper<JiaonafajinEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public JiaonafajinVO selectVO(Wrapper<JiaonafajinEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<JiaonafajinView> selectListView(Wrapper<JiaonafajinEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public JiaonafajinView selectView(Wrapper<JiaonafajinEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}

}
