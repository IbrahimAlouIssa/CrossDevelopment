import { Component, OnInit } from '@angular/core';
import { Todo } from 'src/models/todo.model';
import { DataService } from '../data.service';
import { BehaviorSubject } from 'rxjs';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage implements OnInit {

  
  todos: Todo[];
  constructor(private data: DataService) {
    // this.loadData();
  }

  ngOnInit(){
    this.data.currentTodo.subscribe(todo => this.todos = todo);
  }

  // async loadData(){
  //   this.todos = this.data.todos;
  // }
}

