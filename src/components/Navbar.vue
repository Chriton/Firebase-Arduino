<template>
  <div>
    <v-navigation-drawer temporary absolute v-model="sideNav">
      <v-list>
        <v-list-tile
          v-for="item in menuItems"
          :key="item.title"
          :to="item.link">
          <v-list-tile-action>
            <v-icon left>{{ item.icon }}</v-icon>
          </v-list-tile-action>
          <v-list-tile-content>{{ item.title }}</v-list-tile-content>
        </v-list-tile>
      </v-list>
    </v-navigation-drawer>

    <v-toolbar dark class="purple lighten-2">
      <v-toolbar-side-icon
        @click.stop="sideNav = !sideNav"
        class="hidden-sm-and-up">
      </v-toolbar-side-icon>
      <v-toolbar-title>
        <router-link to="/" tag="span" style="cursor: pointer">Firebse Arduino</router-link>
      </v-toolbar-title>
      <v-spacer></v-spacer>
      <v-toolbar-items class="hidden-xs-only">

        <v-btn v-if="isLoggedIn" flat @click="logout">
          <v-icon left>exit_to_app</v-icon>
          Logout
        </v-btn>

        <v-btn
          flat v-for="item in menuItems"
          :key="item.title"
          :to="item.link">
          <!--@click="item.action"-->

          <v-icon left>{{ item.icon }}</v-icon>
          {{ item.title }}
        </v-btn>
      </v-toolbar-items>
    </v-toolbar>
  </div>
</template>

<script>
  import firebase from 'firebase'

  export default {
    name: "navbar",
    data() {
      return {
        isLoggedIn: false,
        currentUser: false,
        sideNav: false,
        menuItems: [
          { icon: 'face', title: 'Login', link: '/login', action: this.noAction },
          { icon: 'lock_open', title: 'Register', link: '/register', action: this.noAction },
          { icon: 'exit_to_app', title: 'Logout', link: '', action: this.logout },
        ]

      }
    },
    created() {
      if (firebase.auth().currentUser) {
        this.isLoggedIn = true;
        this.currentUser = firebase.auth().currentUser.email;
      }
    },
    methods: {
      logout: function () {
        firebase
          .auth()
          .signOut()
          .then(
            () => {
              // this.$router.push('/login');
              this.$router.go({ path: this.$router.path });
            });
      },
      noAction: function () {
        //do nothing
      }
    }
  }
</script>

<style scoped>

</style>
