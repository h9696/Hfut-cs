package hou.entity.view;

import hou.entity.JiaonafajinEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 缴纳罚金
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2021-03-20 13:31:53
 */
@TableName("jiaonafajin")
public class JiaonafajinView  extends JiaonafajinEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public JiaonafajinView(){
	}
 
 	public JiaonafajinView(JiaonafajinEntity jiaonafajinEntity){
 	try {
			BeanUtils.copyProperties(this, jiaonafajinEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}
