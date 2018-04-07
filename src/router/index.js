import Vue from 'vue'
import Router from 'vue-router'
import Dashboard from '@/components/Dashboard'
import Login from '@/components/User/Login'
import Register from '@/components/User/Register'
import firebase from 'firebase'

Vue.use(Router);

let router = new Router({
  routes: [
    {
      path: '/',
      name: 'dashboard',
      component: Dashboard,
      meta: {
        requiresAuth: true
      }
    },
    {
      path: '/login',
      name: 'login',
      component: Login,
      meta: {
        requiresGuest: true
      }
    },
    {
      path: '/register',
      name: 'register',
      component: Register,
      meta: {
        requiresGuest: true
      }
    }
  ],
  mode: 'history'
});

//Nav Guards
router.beforeEach((to, from, next) => {
  //Check for required auth guard
  if (to.matched.some(record => record.meta.requiresAuth)) {
      //Check if NOT logged in
      if(!firebase.auth().currentUser) {
        //Go to login page
        next({
          path: '/login',
          query: {
            redirect: to.fullPath
          }
        });
      } else {
        //proceed to route
        next();
      }
  } else if (to.matched.some(record => record.meta.requiresGuest)) {
      //Check if logged in
      if(firebase.auth().currentUser) {
        //Go to login page
        next({
          path: '/',
          query: {
            redirect: to.fullPath
          }
        });
      } else {
        //proceed to route
        next();
      }
  } else {
      //proceed to route
      next();
  }
});

export default router;
