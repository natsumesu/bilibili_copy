/*******************侧边排序start***********************/
	var side_nav_tag=0;
	$('#main_aside .side_nav a').on('click',srcGo);
	$('#main_aside .sort').on('click',function(e){
		e.preventDefault();
		
		if(!side_nav_tag){
			$(this).html('<i></i>确定');
			$('#main_aside .side_nav a').off('click');
			$('#main_aside .side_nav ').sortable({
				stop:function(e,u){
					var div_arr=[];
					var target=e.target;
					var lis=$(target).children('li').children('a');
					for(var i=0;i<lis.length;i++){
						var uid=$(lis[i]).attr('href').slice(1);
						//console.log(uid);
						div_arr[div_arr.length]=$('#'+uid);
					}
					$('.content').html('');
        //console.log(u);
					for(var j=0;j<div_arr.length;j++){
						$('.content').append(div_arr[j]);
					}
					styleAll();
					newComicSlide();
					//mainTopSlide();
				}
			});
			$('#main_aside .side_nav ').sortable('enable');
			side_nav_tag=1;
		}else if(side_nav_tag){
			$(this).html('<i></i>排序');
			$('#main_aside .side_nav a').on('click',srcGo);
			$('#main_aside .side_nav ').sortable('disable');
			side_nav_tag=0;
		}
	});
	function srcGo(e){
		e.preventDefault();
		var href = $(this).attr("href");
  	 	var pos = $(href).offset().top;
		$("html,body").animate({ scrollTop: pos }, 300);
		$(this).addClass('active').parent().siblings().children().removeClass('active');
	};
	$(window).scroll(function(){
		var wintop=$(this).scrollTop();
		$('#main_aside .side_nav a').each(function(i){
			var href = $(this).attr("href");
			var pos = $(href).offset().top;
			var posHight=$(href).height();
			if(wintop>=pos-posHight/2){
				$(this).addClass('active').parent().siblings().children().removeClass('active');	
			}
		});
			
		
		
	});
/*******************侧边排序end***********************/
function styleAll(){
	/**sortDate**/
	$(".main_parts>.parts_right>.p_r_top>.sortDate").mouseover(function(){
		$(this).children('.novisibility').show();
	})
	$(".main_parts>.parts_right>.p_r_top>.sortDate").mouseout(function(){
		$(this).children('.novisibility').hide();
	})
	/**新番放送表**/
	$('.new_comic>nav>ul>li').click(function(){
			$(this).addClass('checked').siblings().removeClass('checked');
			var date=$(this).attr('data-date');
			$('.new_comic>div[data-date="'+date+'"]').addClass('checked').siblings().removeClass('checked');
	})
};styleAll();
/************new_comic_right_top_box的轮播效果***********/
var timer1=null;
function newComicSlide(){
	$(".new_comic_right_top .shade_floor02>ul>li").mouseover(function(){
		$(this).addClass("checked").siblings().removeClass("checked");
		var num=$(this).attr("data-toggle").slice(-1);
		//var nowNum=$(".shade_floor01>.shade_box>p.checked").attr("data-toggle").slice(-1);

		comicMoveStep(num);

	})

	function comicMoveStep(num){
		
		$(".shade_floor01>.shade_box").animate({left:-260*num+'px'},100);
		$(".shade_floor01>.shade_box>p[data-toggle='p"+num+"']").addClass("checked").siblings().removeClass("checked");

		$(".new_comic_right_top_box").animate({left:-260*num+'px'},100);
		$(".new_comic_right_top_box>a[data-toggle='p"+num+"']").addClass("checked").siblings().removeClass("checked");
	}

	function comicMove(){
			var num=parseInt($(".shade_floor01>.shade_box>p.checked").attr("data-toggle").slice(-1));
				num++;
				if(num>2){num=0};
				comicMoveStep(num);
				$(".shade_floor02>ul>li[data-toggle='p"+num+"']").addClass("checked").siblings().removeClass("checked");
	}
	
	
	clearInterval(timer1);
	timer1=setInterval(comicMove,2000);

	$(".new_comic_right_top").mouseout(function(event){

		timer1=setInterval(comicMove,2000);
	})

	$(".new_comic_right_top").mouseover(function(event){

		clearInterval(timer1);
	})
};newComicSlide();
	/*************************main_top_left的轮播*******************************/
//function mainTopSlide(){
	$('.main_top>.main_top_left>.list_bottom>.list_slider>li').click(function(){
		$(this).addClass("checked").siblings().removeClass("checked");
		var num=$(this).attr("data-toggle").slice(-1);
		mainTopMoveStep(num);
	});
	function mainTopMoveStep(num){
		$(".main_top>.main_top_left>.list").animate({left:-440*num+'px'},100);
		$(".main_top>.main_top_left>.list>li[data-toggle='i"+num+"']").addClass("checked").siblings().removeClass("checked");

		$(".main_top>.main_top_left>.list_bottom>.title>span[data-toggle='i"+num+"']").addClass("checked").siblings().removeClass("checked");
	};
	function mainTopMove(){
		var num=parseInt($(".main_top>.main_top_left>.list>li.checked").attr("data-toggle").slice(-1));
		num++;
		if(num>5){num=0};
		mainTopMoveStep(num);
		$(".main_top>.main_top_left>.list_bottom>.list_slider>li[data-toggle='i"+num+"']").addClass("checked").siblings().removeClass("checked");
	}

	var timer2=setInterval(mainTopMove,2000);

	$(".main_top>.main_top_left").mouseout(function(event){

		timer2=setInterval(mainTopMove,2000);
	})

	$(".main_top>.main_top_left").mouseover(function(event){

		clearInterval(timer2);
	})
//};mainTopSlide();
	
	
		
