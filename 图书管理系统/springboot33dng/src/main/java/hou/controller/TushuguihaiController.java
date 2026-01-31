package hou.controller;

import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Map;
import java.util.Date;
import javax.servlet.http.HttpServletRequest;

import hou.entity.TushuxinxiEntity;
import hou.service.TushuxinxiService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.mapper.Wrapper;

import hou.entity.TushuguihaiEntity;
import hou.entity.view.TushuguihaiView;

import hou.service.TushuguihaiService;
import hou.utils.PageUtils;
import hou.utils.R;
import hou.utils.MPUtil;


/**
 * 图书归还
 * 后端接口
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
@RestController
@RequestMapping("/tushuguihai")
public class TushuguihaiController {
    @Autowired
    private TushuguihaiService tushuguihaiService;
    @Autowired
    private TushuxinxiService tushuxinxiService;
    


    /**
     * 后端列表
     */
    @RequestMapping("/page")
    public R page(@RequestParam Map<String, Object> params,TushuguihaiEntity tushuguihai,
		HttpServletRequest request){
		String tableName = request.getSession().getAttribute("tableName").toString();
		if(tableName.equals("yonghu")) {
			tushuguihai.setYonghuming((String)request.getSession().getAttribute("username"));
		}
        EntityWrapper<TushuguihaiEntity> ew = new EntityWrapper<TushuguihaiEntity>();
		PageUtils page = tushuguihaiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, tushuguihai), params), params));

        return R.ok().put("data", page);
    }
    
    /**
     * 前端列表
     */
    @RequestMapping("/list")
    public R list(@RequestParam Map<String, Object> params,TushuguihaiEntity tushuguihai, HttpServletRequest request){
        EntityWrapper<TushuguihaiEntity> ew = new EntityWrapper<TushuguihaiEntity>();
		PageUtils page = tushuguihaiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, tushuguihai), params), params));
        return R.ok().put("data", page);
    }

	/**
     * 列表
     */
    @RequestMapping("/lists")
    public R list( TushuguihaiEntity tushuguihai){
       	EntityWrapper<TushuguihaiEntity> ew = new EntityWrapper<TushuguihaiEntity>();
      	ew.allEq(MPUtil.allEQMapPre( tushuguihai, "tushuguihai")); 
        return R.ok().put("data", tushuguihaiService.selectListView(ew));
    }

	 /**
     * 查询
     */
    @RequestMapping("/query")
    public R query(TushuguihaiEntity tushuguihai){
        EntityWrapper< TushuguihaiEntity> ew = new EntityWrapper< TushuguihaiEntity>();
 		ew.allEq(MPUtil.allEQMapPre( tushuguihai, "tushuguihai")); 
		TushuguihaiView tushuguihaiView =  tushuguihaiService.selectView(ew);
		return R.ok("查询图书归还成功").put("data", tushuguihaiView);
    }
	
    /**
     * 后端详情
     */
    @RequestMapping("/info/{id}")
    public R info(@PathVariable("id") Long id){
        TushuguihaiEntity tushuguihai = tushuguihaiService.selectById(id);
        return R.ok().put("data", tushuguihai);
    }

    /**
     * 前端详情
     */
    @RequestMapping("/detail/{id}")
    public R detail(@PathVariable("id") Long id){
        TushuguihaiEntity tushuguihai = tushuguihaiService.selectById(id);
        return R.ok().put("data", tushuguihai);
    }




    /**
     * 后端保存
     */
    @RequestMapping("/save")
    public R save(@RequestBody TushuguihaiEntity tushuguihai, HttpServletRequest request){
    	tushuguihai.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(tushuguihai);
        tushuguihaiService.insert(tushuguihai);
        return R.ok();
    }

    /**
     * 前端保存
     */
    @RequestMapping("/add")
    public R add(@RequestBody TushuguihaiEntity tushuguihai, HttpServletRequest request){
    	tushuguihai.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(tushuguihai);
        tushuguihaiService.insert(tushuguihai);
        return R.ok();
    }

    /**
     * 修改
     */
    @RequestMapping("/update")
    public R update(@RequestBody TushuguihaiEntity tushuguihai, HttpServletRequest request){
        //ValidatorUtils.validateEntity(tushuguihai);
        tushuguihaiService.updateById(tushuguihai);//全部更新

        // 更新图书信息的可借数量
        String tushubianhao = tushuguihai.getTushubianhao();
        if (tushubianhao != null) {
            EntityWrapper<TushuxinxiEntity> wrapper = new EntityWrapper<>();
            wrapper.eq("tushubianhao", tushubianhao);
            TushuxinxiEntity tushuxinxi = tushuxinxiService.selectOne(wrapper);
            if (tushuxinxi != null) {
                tushuxinxi.setKejieshuliang(tushuxinxi.getKejieshuliang() + 1);
                tushuxinxiService.updateById(tushuxinxi);
            }
        }

        return R.ok();
    }

    

    /**
     * 删除
     */
    @RequestMapping("/delete")
    public R delete(@RequestBody Long[] ids){
        tushuguihaiService.deleteBatchIds(Arrays.asList(ids));
        return R.ok();
    }
    
    /**
     * 提醒接口
     */
	@RequestMapping("/remind/{columnName}/{type}")
	public R remindCount(@PathVariable("columnName") String columnName, HttpServletRequest request, 
						 @PathVariable("type") String type,@RequestParam Map<String, Object> map) {
		map.put("column", columnName);
		map.put("type", type);
		
		if(type.equals("2")) {
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
			Calendar c = Calendar.getInstance();
			Date remindStartDate = null;
			Date remindEndDate = null;
			if(map.get("remindstart")!=null) {
				Integer remindStart = Integer.parseInt(map.get("remindstart").toString());
				c.setTime(new Date()); 
				c.add(Calendar.DAY_OF_MONTH,remindStart);
				remindStartDate = c.getTime();
				map.put("remindstart", sdf.format(remindStartDate));
			}
			if(map.get("remindend")!=null) {
				Integer remindEnd = Integer.parseInt(map.get("remindend").toString());
				c.setTime(new Date());
				c.add(Calendar.DAY_OF_MONTH,remindEnd);
				remindEndDate = c.getTime();
				map.put("remindend", sdf.format(remindEndDate));
			}
		}
		
		Wrapper<TushuguihaiEntity> wrapper = new EntityWrapper<TushuguihaiEntity>();
		if(map.get("remindstart")!=null) {
			wrapper.ge(columnName, map.get("remindstart"));
		}
		if(map.get("remindend")!=null) {
			wrapper.le(columnName, map.get("remindend"));
		}

		String tableName = request.getSession().getAttribute("tableName").toString();
		if(tableName.equals("yonghu")) {
			wrapper.eq("yonghuming", (String)request.getSession().getAttribute("username"));
		}

		int count = tushuguihaiService.selectCount(wrapper);
		return R.ok().put("count", count);
	}
	


}
