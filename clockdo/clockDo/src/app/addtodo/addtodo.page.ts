import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-addtodo',
  templateUrl: './addtodo.page.html',
  styleUrls: ['./addtodo.page.scss'],
})
export class AddtodoPage implements OnInit {

  values = [];
  timer: any;
  constructor() { }

  ngOnInit() {
  }

  removeInput(i){
    this.values.splice(i,1);

  }

  addInput(){
    this.values.push({value: ""});
  }

}
