import Vue from 'vue'
import App from './App'
import * as firebase from 'firebase'
import router from './router'
import Vuetify from 'vuetify'
import 'vuetify/dist/vuetify.min.css'
import { store } from './store'
import AlertCmp from './components/Shared/Alert.vue'

Vue.use(Vuetify, { theme: {
  primary: '#ee44aa',
  secondary: '#424242',
  accent: '#82B1FF',
  error: '#FF5252',
  info: '#2196F3',
  success: '#4CAF50',
  warning: '#FFC107'
}})

Vue.config.productionTip = false;

Vue.component('app-alert', AlertCmp);

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  store,
  render: h => h(App),
  created () {
    firebase.initializeApp({
      apiKey: "AIzaSyBDKp5piWzCpHpOBzuPQPCI4fxFYU3rp4E",
      authDomain: "fir-arduino-1.firebaseapp.com",
      databaseURL: "https://fir-arduino-1.firebaseio.com",
      projectId: "fir-arduino-1",
      storageBucket: "fir-arduino-1.appspot.com",
      messagingSenderId: "1007645832525"
    });
    this.$store.dispatch('loadSensorData')
  }
});
