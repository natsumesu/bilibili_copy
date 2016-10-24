console.log('11111111111111')

$('#main_header .header_box p>a.login').click(function(){
    $('#main_header>.modal').fadeIn();
})
$('#main_header>.modal>.modal-dialog>.modal-content>span').click(function(){
    $('#main_header>.modal').fadeOut();
})


if(localStorage.getItem('uname')){
$('#main_header .header_box p>a.login').html(localStorage.getItem('uname')+',欢迎回来');
};

$('#login_form>input.submit').click(function(){
	
	var value=$('#login_form>input[name="code"]').val();
	
	if(value.toLowerCase()!=code.toLowerCase()||!value){
		$('#login_form .code_info').html('验证码不正确！');
		console.log(value+""+code);
	}else{
		var result=$('#login_form').serialize();
		console.log(result);
		code="";
		$.post('php/login.php',result,function(data){
			console.log(data);
			if(data.status<0){
				$('#login_form>span.all_info').html(data.msg);
				$('[name="uname"]').val('');
				$('[name="upwd"]').val('');
			}else{
				$('#main_header .header_box p>a.login').html(data.msg+',欢迎回来');
				$('#main_header>.modal').fadeOut();
				$('#main_header .header_box p>a.login').off('click').css('color','#e65887');
				localStorage.setItem('uname',data.msg);
			}
		})
	}
});
$('#login_form>input[name="uname"]').blur(function(){
    var value=$(this).val();
    var reg=/(^\w+@\w+\.com$)|(^1\w{12}$)/;
    var result=reg.test(value);
    if(!result){
        $('#login_form>.uname_info').html('手机/邮箱格式不正确！');
		//$('#login_form>.submit').attr('disabled','true');
    }else{
		
		$('#login_form>.uname_info').html("&nbsp;");
		//$('#login_form>.submit').attr('disabled','false');
	}
})
$('#login_form>input[name="upwd"]').blur(function(){
    var value=$(this).val();
    var reg=/^\w{6,15}$/;
    var result=reg.test(value);
    if(!result){
        $('#login_form>.upwd_info').html('密码长度为6~15位！');
		//$('#login_form>.submit').attr('disabled','true');
    }else{
		console.log('222');
		$('#login_form>.upwd_info').html('&nbsp;');
		//$('#login_form>.submit').attr('disabled','false');
	}
})
var code='';
$('#login_form>input[name="code"]').focus(function(){
	if($('#codesvg').css('display')=='none'){
		$('#codesvg').html('');
		$('#codesvg').fadeIn();
		codemake();
	}
});
$('#codesvg').click(function(){
	$(this).html('');
	codemake();
});
function codemake(){
	var bg=document.createElementNS('http://www.w3.org/2000/svg','rect');
	codesvg.appendChild(bg);
	var db='zxcvbnmadsfghjklpoiuytrewqZXCVBNMLKJHGFDSAQWERTYUIOP0987654321';
	var txt='';
	code='';
	for (var i=0;i<4;i++)
	{
		var num=random(0,db.length);
		txt=db[num];
		code+=txt;
		var text=document.createElementNS('http://www.w3.org/2000/svg','text');
		text.setAttribute('font-size',20);
		text.setAttribute('font-family','SimHei');
		text.setAttribute('fill',rgb(50,160));
		text.setAttribute('x',i*20+random(-5,5)+20);
		text.setAttribute('y',20+random(-5,5));
		text.setAttribute('rotate',random(-45,45));
		text.innerHTML=txt;
		codesvg.appendChild(text);

		var line=document.createElementNS('http://www.w3.org/2000/svg','line');
		line.setAttribute('x1',random(0,100));
		line.setAttribute('y1',random(0,30));
		line.setAttribute('x2',random(0,100));
		line.setAttribute('y3',random(0,30));
		line.setAttribute('stroke',rgb(50,160));

		codesvg.appendChild(line);
	  }
		function random(x,y){
			var num=Math.floor(Math.random()*(y-x)+x);
			return num;
		}
		function rgb(min,max){
			var r=Math.floor(Math.random()*(max-min)+min);
			var g=Math.floor(Math.random()*(max-min)+min);
			var b=Math.floor(Math.random()*(max-min)+min);
			return 'rgb('+r+','+g+','+b+')';
		}	
}