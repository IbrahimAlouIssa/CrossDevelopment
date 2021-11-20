import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-timer',
  templateUrl: './timer.component.html',
  styleUrls: ['./timer.component.scss'],
})
export class TimerComponent implements OnInit {

  interval: any = false;
  timer = 630;
  startTimer: any = false;
  

  constructor() {
    
   }

  ngOnInit() { 
       setInterval(() => {
         if(this.startTimer)
         {
           this.timer -= 5;
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
