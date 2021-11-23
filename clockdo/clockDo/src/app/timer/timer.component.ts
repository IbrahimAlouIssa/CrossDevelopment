import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'app-timer',
  templateUrl: './timer.component.html',
  styleUrls: ['./timer.component.scss'],
})
export class TimerComponent implements OnInit {


  @Input()
  time: string;
  interval: any = false;
  timer = 630;
  startTimer: any = false;
  min: number;
  sec: number;
  
  constructor() {
    
   }

  ngOnInit() { 
    let split = this.time.split(':')
    this.min = +split[0] 
    this.sec = +split[1]
    let min = +split[0] * 60  
    let interval = min + +split[1];
    interval = 630/interval
    console.log(interval)
      let intervalId = setInterval(() => {
         if(this.startTimer)
         {
           this.timer -= interval;
           if(this.sec - 1 == - 1){
            this.min -= 1;
            this.sec = 59;
          }else{
            this.sec -= 1
          }
          if (this.min === 0 && this.sec == 0) clearInterval(intervalId)
         }
         
       }, 1000)
    }

   start(){
     if(this.startTimer === false){
       this.startTimer = true;
     }else{
        this.startTimer = false;
     }
    
   }



}
