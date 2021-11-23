import { Injectable, OnInit } from '@angular/core';
import { Todo } from 'src/models/todo.model';
import { Storage } from '@capacitor/storage';
import { BehaviorSubject } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class DataService{  
  private todo = new BehaviorSubject<Todo[]>([]);
  currentTodo = this.todo.asObservable();

  constructor() {
    this.init()
   }

  async updateTodo(todo: Todo[]){
    this.todo.next(todo);

    await Storage.set({
      key: 'todos',
      value: JSON.stringify(todo)
    }); 

  }

  async init() {
    const item = await Storage.get({key: 'todos'});
    this.updateTodo(JSON.parse(item.value));

  }

  // async addTodo(todo: Todo){
  //   this.todos.push(todo);
  //   console.log(this.todos);
  //   await Storage.set({
  //     key: 'todos',
  //     value: JSON.stringify(this.todos)
  //   }); 
  //  }

  // async getTodos(){
  // }

  // getData(){
  //   return this.storage.get('todo') || [];
  // }

  // async addData(todo: Todo){
  //   const storedData = await this.storage.get('todo') || [];
  //   storedData.push(todo);
  //   return this.storage.set('todo', storedData);
  // }
  

}
