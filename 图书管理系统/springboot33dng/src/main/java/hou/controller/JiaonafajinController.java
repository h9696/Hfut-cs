package hou.controller;

import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Map;
import java.util.Date;
import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.mapper.Wrapper;

import hou.entity.JiaonafajinEntity;
import hou.entity.view.JiaonafajinView;

import hou.service.JiaonafajinService;
import hou.utils.PageUtils;
import hou.utils.R;
import hou.utils.MPUtil;


/**
 * 缴纳罚金
 * 后端接口
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
@RestController
@RequestMapping("/jiaonafajin")
public class JiaonafajinController {
    @Autowired
    private JiaonafajinService jiaonafajinService;
    


    /**
     * 后端列表
     */
    @RequestMapping("/page")
    public R page(@RequestParam Map<String, Object> params,JiaonafajinEntity jiaonafajin,
		HttpServletRequest request){
		String tableName = request.getSession().getAttribute("tableName").toString();
		if(tableName.equals("yonghu")) {
			jiaonafajin.setYonghuming((String)request.getSession().getAttribute("username"));
		}
        EntityWrapper<JiaonafajinEntity> ew = new EntityWrapper<JiaonafajinEntity>();
		PageUtils page = jiaonafajinService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, jiaonafajin), params), params));

        return R.ok().put("data", page);
    }
    
    /**
     * 前端列表
     */
    @RequestMapping("/list")
    public R list(@RequestParam Map<String, Object> params,JiaonafajinEntity jiaonafajin, HttpServletRequest request){
        EntityWrapper<JiaonafajinEntity> ew = new EntityWrapper<JiaonafajinEntity>();
		PageUtils page = jiaonafajinService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, jiaonafajin), params), params));
        return R.ok().put("data", page);
    }

	/**
     * 列表
     */
    @RequestMapping("/lists")
    public R list( JiaonafajinEntity jiaonafajin){
       	EntityWrapper<JiaonafajinEntity> ew = new EntityWrapper<JiaonafajinEntity>();
      	ew.allEq(MPUtil.allEQMapPre( jiaonafajin, "jiaonafajin")); 
        return R.ok().put("data", jiaonafajinService.selectListView(ew));
    }

	 /**
     * 查询
     */
    @RequestMapping("/query")
    public R query(JiaonafajinEntity jiaonafajin){
        EntityWrapper< JiaonafajinEntity> ew = new EntityWrapper< JiaonafajinEntity>();
 		ew.allEq(MPUtil.allEQMapPre( jiaonafajin, "jiaonafajin")); 
		JiaonafajinView jiaonafajinView =  jiaonafajinService.selectView(ew);
		return R.ok("查询缴纳罚金成功").put("data", jiaonafajinView);
    }
	
    /**
     * 后端详情
     */
    @RequestMapping("/info/{id}")
    public R info(@PathVariable("id") Long id){
        JiaonafajinEntity jiaonafajin = jiaonafajinService.selectById(id);
        return R.ok().put("data", jiaonafajin);
    }

    /**
     * 前端详情
     */
    @RequestMapping("/detail/{id}")
    public R detail(@PathVariable("id") Long id){
        JiaonafajinEntity jiaonafajin = jiaonafajinService.selectById(id);
        return R.ok().put("data", jiaonafajin);
    }
    



    /**
     * 后端保存
     */
    @RequestMapping("/save")
    public R save(@RequestBody JiaonafajinEntity jiaonafajin, HttpServletRequest request){
    	jiaonafajin.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(jiaonafajin);
        jiaonafajinService.insert(jiaonafajin);
        return R.ok();
    }
    
    /**
     * 前端保存
     */
    @RequestMapping("/add")
    public R add(@RequestBody JiaonafajinEntity jiaonafajin, HttpServletRequest request){
    	jiaonafajin.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(jiaonafajin);
        jiaonafajinService.insert(jiaonafajin);
        return R.ok();
    }

    /**
     * 修改
     */
    @RequestMapping("/update")
    public R update(@RequestBody JiaonafajinEntity jiaonafajin, HttpServletRequest request){
        //ValidatorUtils.validateEntity(jiaonafajin);
        jiaonafajinService.updateById(jiaonafajin);//全部更新
        return R.ok();
    }
    

    /**
     * 删除
     */
    @RequestMapping("/delete")
    public R delete(@RequestBody Long[] ids){
        jiaonafajinService.deleteBatchIds(Arrays.asList(ids));
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
		
		Wrapper<JiaonafajinEntity> wrapper = new EntityWrapper<JiaonafajinEntity>();
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

		int count = jiaonafajinService.selectCount(wrapper);
		return R.ok().put("count", count);
	}
	


}
