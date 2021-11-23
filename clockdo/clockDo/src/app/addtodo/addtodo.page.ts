import { Component, OnInit } from '@angular/core';
import { Todo } from 'src/models/todo.model';
import { DataService } from '../data.service';
import { Router } from '@angular/router';
@Component({
  selector: 'app-addtodo',
  templateUrl: './addtodo.page.html',
  styleUrls: ['./addtodo.page.scss'],
})
export class AddtodoPage implements OnInit {

  values = [];
  timer: any;
  goals: Array<string> = [];
  title: string;
  todos: Array<Todo>;

  
  constructor(private data: DataService, private router: Router) { }

  ngOnInit() {
    this.values.push({value: ""});
    this.data.currentTodo.subscribe(todo => this.todos = todo);

  }

  removeInput(i){
    this.values.splice(i,1);
  }

  addInput(){
    this.values.push({value: ""});
  }

  add(){
    console.log(this.timer)
    let time = this.timer.slice(14,19)
    
    for(let goal of this.values){
      this.goals.push(goal.goal);
    }
    let task = new Todo(this.title,this.goals,time)
    this.todos = this.todos || [];
    this.todos.push(task) ;
    this.data.updateTodo(this.todos);
    this.router.navigateByUrl('/home');
    //console.log(this.values);
  }

}
