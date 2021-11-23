import { Component, Input, OnInit } from '@angular/core';
import { Todo } from 'src/models/todo.model';
import { DataService } from '../data.service';
@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.scss'],
})
export class CardComponent implements OnInit {

  @Input()
  todo: Todo;
  @Input()
  index: number;
  title: string;
  goals: string[];
  time: string;
  todos: Array<Todo>;


  constructor(private data: DataService) {
    this.data.currentTodo.subscribe(todo => this.todos = todo);

   }

  ngOnInit() {
    this.title = this.todo.name;
    this.goals = this.todo.goals;
    this.time = this.todo.time;
  }

  delete(){
    this.todos.splice(this.index, 1); 
    console.log(this.todos)
    this.data.updateTodo(this.todos);
  }

}
