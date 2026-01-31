package hou.service.impl;

import org.springframework.stereotype.Service;
import java.util.Map;
import java.util.List;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.plugins.Page;
import com.baomidou.mybatisplus.service.impl.ServiceImpl;
import hou.utils.PageUtils;
import hou.utils.Query;


import hou.dao.TushuguihaiDao;
import hou.entity.TushuguihaiEntity;
import hou.service.TushuguihaiService;
import hou.entity.vo.TushuguihaiVO;
import hou.entity.view.TushuguihaiView;

@Service("tushuguihaiService")
public class TushuguihaiServiceImpl extends ServiceImpl<TushuguihaiDao, TushuguihaiEntity> implements TushuguihaiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<TushuguihaiEntity> page = this.selectPage(
                new Query<TushuguihaiEntity>(params).getPage(),
                new EntityWrapper<TushuguihaiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<TushuguihaiEntity> wrapper) {
		  Page<TushuguihaiView> page =new Query<TushuguihaiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<TushuguihaiVO> selectListVO(Wrapper<TushuguihaiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public TushuguihaiVO selectVO(Wrapper<TushuguihaiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<TushuguihaiView> selectListView(Wrapper<TushuguihaiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public TushuguihaiView selectView(Wrapper<TushuguihaiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}

}
