<template>
  <v-app>
    <v-navigation-drawer temporary absolute v-model="sideNav">
      <v-list>
        <v-list-tile
          v-for="item in menuItems"
          :key="item.title"
          :to="item.link">
          <v-list-tile-action>
            <v-icon>{{ item.icon }}</v-icon>
          </v-list-tile-action>
          <v-list-tile-content>{{ item.title }}</v-list-tile-content>
        </v-list-tile>
        <v-list-tile v-if="userIsAuthenticated" @click="onLogout">
          <v-list-tile-action>
            <v-icon>exit_to_app</v-icon>
          </v-list-tile-action>
          <v-list-tile-content>Logout</v-list-tile-content>
        </v-list-tile>
      </v-list>
    </v-navigation-drawer>
    <v-toolbar>
      <v-toolbar-side-icon
        @click.stop="sideNav = !sideNav"
        class="hidden-md-and-up">
      </v-toolbar-side-icon>
      <v-toolbar-title class="hidden-xs-and-down">
        <router-link to="/" tag="span" style="cursor: pointer">Firebase Arduino</router-link>
      </v-toolbar-title>
      <v-spacer></v-spacer>
      <v-toolbar-items>
        <v-btn
          flat
          v-for="item in menuItems"
          :key="item.title"
          :to="item.link">
          <v-icon left>{{ item.icon }}</v-icon>
          <v-container class="hidden-sm-and-down">{{ item.title }}</v-container>
        </v-btn>
        <v-btn flat v-if="userIsAuthenticated" @click="onLogout">
          <v-icon left>exit_to_app</v-icon>
          <v-container class="hidden-sm-and-down">Logout</v-container>
        </v-btn>
      </v-toolbar-items>
    </v-toolbar>
    <main>
      <router-view></router-view>
    </main>
    <Footer/>
  </v-app>
</template>

<script>
  import Footer from '@/components/Footer'

  export default {
    name: 'App',
    data() {
      return {
        sideNav: false
      }
    },
    computed: {
      menuItems () {
        let menuItems = [
          {icon: 'face', title: 'Sign up', link: '/signup'},
          {icon: 'lock_open', title: 'Sign in', link: '/signin'}
        ];
        if (this.userIsAuthenticated) {
          menuItems = [
            {icon: 'graphic_eq', title: 'View Data', link: '/sensor'},
            {icon: 'person', title: 'Profile', link: '/profile'}
          ];
        }
        return menuItems
      },
      userIsAuthenticated () {
        return this.$store.getters.user !== null && this.$store.getters.user !== undefined
      }
    },
    methods: {
      onLogout () {
        this.$store.dispatch('logout')
      }
    },
    components: {
      Footer
    }
  }
</script>



<style>

</style>
