import Vue from 'vue'
import Vuex from 'vuex'
import * as firebase from 'firebase'
import router from '@/router'

Vue.use(Vuex);

export const store = new Vuex.Store({
  state: {
    user: null,
    loading: false,
    error: null,
    sensorData: {}
  },
  mutations: {
    setUser (state, payload) {
      state.user = payload
    },
    setLoading (state, payload) {
      state.loading = payload
    },
    setError (state, payload) {
      state.error = payload
    },
    clearError (state) {
      state.error = null
    },
    setSensorData (state, payload) {
      state.sensorData = payload
    }
   },
  actions: {
    signUserUp ({commit}, payload) {
        commit('setLoading', true);
        commit('clearError');
        firebase.auth().createUserWithEmailAndPassword(payload.email, payload.password)
          .then(
            user => {
              commit('setLoading', false);
              const newUser = {
                id: user.uid
              };
              commit('setUser', newUser);
            }
          )
          .catch(
            error => {
              commit('setLoading', false);
              commit('setError', error);
            }
          )
    },
    signUserIn ({commit}, payload) {
      commit('setLoading', true);
      commit('clearError');
        firebase.auth().signInWithEmailAndPassword(payload.email, payload.password)
          .then(
            user => {
              commit('setLoading', false);
              const newUser =  {
                id: user.uid
              };
              commit('setUser', newUser);
            }
          )
          .catch(
            error => {
              commit('setLoading', false);
              commit('setError', error);
            }
          )
    },
    clearError ({commit}) {
      commit('clearError')
    },
    autoSignIn ({commit}, payload) {
      commit('setUser', { id: payload.uid })
    },
    logout ({commit}) {
      firebase.auth().signOut()
        .then( () => {
          commit('setUser', null);
          router.push('/')
        })
        .catch(
          error => {
          //TODO
        })
    },
    loadSensorData ({commit}) {
      commit('setLoading', true);
      firebase.database().ref('sensors/sensor1').on('value', snapshot => {
        commit('setSensorData', snapshot.val());
        commit('setLoading', false);
      })
    }
  },
  getters: {
    user (state) {
      return state.user
    },
    loading (state) {
      return state.loading
    },
    error (state) {
    return state.error
    },
    sensorData (state) {
      return state.sensorData
    }
  }
});
