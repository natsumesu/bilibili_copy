var videolist=['Larva S01E02 - Mosquito.mp4',
		'Larva S01E03 - Dancing In The Rain.mp4',
		'Larva S01E04 - Mushroom.mp4',
		'Larva S01E05 -  Gum 1.mp4',
		'Larva S01E06 -  Ice Road.mp4',
		'Larva S01E07 -  Straw.mp4',
		'Larva S01E08 -  Insectivorous Plant.mp4',
		'Larva S01E09 - Snail.mp4',
		'Larva S01E10 - Snoring.mp4',
		'Larva S01E11 - Popcorn.mp4',
		'Larva S01E13 -  Ham.mp4',
		'Larva S01E14 - ESP.mp4',
		'Larva S01E15 - Fly.mp4',
		'Larva S01E16 - Spaghetti.mp4',
		'Larva S01E17 - Airform.mp4',
		'Larva S01E18 - Cocoon 1.mp4',
		'Larva S01E19 - Cocoon 2.mp4',
		'Larva S01E20 - Pudding.mp4',
		'Larva S01E21 -  Watermelon.mp4',
		'Larva S01E22 - UFO.mp4',
		'Larva s01e23 - Fishing.mp4',
		'Larva S01E24 - Out of Body.mp4',
		'Larva S01E25 - Hot Spring.mp4',
		'Larva S01E26 - Hide and Seek.mp4',
		'Larva S01E27 - Earthquake.mp4',
		'Larva S01E28 - Hair-growth Solution.mp4',
		'Larva S01E29 - Flood 1.mp4',
		'Larva S01E31 - Walnuts.mp4',
		'Larva S01E32 - Soda.mp4',
		'Larva S01E35 - Decay.mp4',
		'Larva S01E36 - Coin Toss.mp4',
		'Larva S01E37 - Concert.mp4',
		'Larva S01E38 - Snowball Fight.mp4',
		'Larva S01E40 - Ant.mp4',
		'Larva S01E41 - Stomachache.mp4',
		'Larva S01E42 - Mummy.mp4',
		'Larva S01E43 - Bee 1.mp4',
		'Larva S01E47 - Christmas.mp4',
		'Larva S01E48 - Yellow-terminator.mp4',
		'Larva S01E49 - The Cement.mp4',
		'Larva S01E50 - Larvatar.mp4',
		'Larva S01E51 - Hip Hop.mp4',
		'Larva S01E52 - Snot.mp4',
		'Larva S01E53 - Halling.mp4',
		'Larva S01E54 - Pit.mp4',
		'Larva S01E56 - Raining.mp4',
		'Larva S01E57 - Glove.mp4',
		'Larva S01E58 - Laughing.mp4',
		'Larva S01E59 - Eye Infection.mp4',
		'Larva S01E60 - Missing.mp4',
		'Larva S01E61 - Wig.mp4',
		'Larva S01E62 - Vampire.mp4',
		'Larva S01E63 - Clock.mp4',
		'Larva S01E65 - Perfume.mp4',
		'Larva S01E66 - Super Glue.mp4',
		'Larva S01E67 - Swing.mp4',
		'Larva S01E68 - Growing a Plant.mp4',
		'Larva S01E69 - Bee 2.mp4',
		'Larva S01E70 - Scary Night.mp4',
		'Larva S01E71 - Rope.mp4',
		'Larva S01E72 - Spider.mp4',
		'Larva S01E73 - Super Liquid.mp4',
		'Larva S01E74 - Nightmare.mp4',
		'Larva S01E75 - Chick 1.mp4',
		'Larva S01E76 - Chick 2.mp4',
		'Larva S01E77 - Farting.mp4',
		'Larva S01E78 - Secret of Snail.mp4',
		'Larva S01E85 - Chili Show.mp4',
		'Larva S01E86 - Alien.mp4',
		'Larva S01E94 - Electronic Shock.mp4',
		'Larva S01E95 - Whistle.mp4',
		'Larva S01E96 - Diving.mp4',
		'Larva S01E97 - Fire.mp4',
		'Larva S01E98 - Seesaw.mp4',
		'Larva S01E99 - Water Show.mp4'
		];

window.onload=function(){
	/* 获取服务器弹幕 */
	var room=$('#avcode').html();
	var pop_msg=[];

	/* 获取弹幕 */
	$.get('php/getdanmu.php',{'room':room},function(data){
		if(!data.length){return ;}
					
		//console.log(data[0].time);
		for(var i=0;i<data.length;i++){
			data[i].time=parseFloat(data[i].time).toFixed(2);
			pop_msg.push(data[i]);
			var content=data[i].content;
			var times=data[i].time;
			var $span=$('<span></span>');
			$span.html(content);
			var $times=$('<time></time>');
			$times.html(times);
			var $li=$('<li></li>');
			$li.append($span).append($times).appendTo($('#msgwin'));
			
		}
		
	})

	/* 绑定选集按钮事件 */
		$('#range li:not(.show_more)').click(function(){
			$('#range li.active').removeClass('active');
			$(this).addClass('active');
			var i=$(this).html().slice(1);
			i=parseInt(i);
			var arr=videolist[i-1];
			$('#vd').attr('src','videos/larva/'+arr);

		});
		$('#range li.show_more').click(function(){
			$(this).css('display','none');
			$('#range').removeClass('shrink');
		});
	
	/*****绑定发送按钮*******/
	
		$('#send_msg').click(function(){
			var msg_time=vd.currentTime.toFixed(2);
			if(!msg_time){msg_time=0};
			var msg_con=$('#msg').val();
			if(!msg_con){return ;}
			var msg_color=$('#msg_color').val();
			$.post('php/senddanmu.php',{'room':room,'msg':msg_con,'time':msg_time,'color':msg_color},
				function(data){
				$('#msg').val('');
				
				pop_msg.push({
					'color':msg_color,
					'content':msg_con,
					'time':msg_time
				});
				var $span=$('<span></span>');
				$span.html(msg_con);
				var $times=$('<time></time>');
				$times.html(msg_time);
				var $li=$('<li></li>');
				$li.append($span).append($times).appendTo($('#msgwin'));
				
			});
		});

	/*  弹幕事件  */
	
		vd.onplay=function(){
			var vdtime=setInterval(function(){
				$('#pop_win span:not([class])').each(function(){
					$(this).addClass('active');
				});
				$('#pop_win span').each(function(){
					if($(this).css('color')=='rgba(0, 0, 0, 0)'){
						$(this).remove();
					}
				});
				var time=vd.currentTime;
				for(var i=0;i<pop_msg.length;i++){
					if(pop_msg[i].time<=time&&pop_msg[i].time>=time-2){
						var $span=$('<span></span>');
						$span.css('color',pop_msg[i].color);
						$span.css('top',Math.floor(Math.random()*250));

						$span.html(pop_msg[i].content);
						$('#pop_win').append($span);
						pop_msg.splice(i,1);
					}
				}
			},500);
		};
	

}