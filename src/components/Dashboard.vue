<template>
  <v-container fluid grid-list-lg>
    <v-layout row wrap justify-center>
      <v-flex xs12 sm12 md6>
        <v-card>
          <!--<v-toolbar>-->
            <!--<v-toolbar-side-icon></v-toolbar-side-icon>-->
          <!--</v-toolbar>-->
          <v-card-text style="height: 300px;" class="grey lighten-5">
            <div>The Dashboard Page</div>
            <div>
              <ul>
                <li v-for="employee in employees"
                v-bind:key="employee.id">
                  {{ employee.employee_id}}
                  {{ employee.name }}
                  {{ employee.dept }}
                  {{ employee.position }}
                </li>
              </ul>
            </div>
          </v-card-text>

          <v-card-text style="height: 100px; position: relative">
            <v-btn
              absolute
              dark
              fab
              top
              right
              color="pink"
            >
              <v-icon>add</v-icon>
            </v-btn>
          </v-card-text>
        </v-card>
      </v-flex>
    </v-layout>
  </v-container>

</template>

<script>
  import db from '@/components/firebaseInit'
  export default {
    name: "Dashboard",
    data () {
      return {
        employees: []
      }
    },
    created () {
      // db.collection('employees').get().then(querySnapshot => {
      // // db.collection('employees').orderBy('dept').get().then(querySnapshot => {
      //   querySnapshot.forEach(doc => {
      //     console.log(doc.data());
      //     console.log(doc.id);
      //     const data = {
      //       'id': doc.id,
      //       'employee_id': doc.data().employee_id,
      //       'name': doc.data().name,
      //       'dept': doc.data().dept,
      //       'position': doc.data().position,
      //     };
      //     this.employees.push(data)
      //   })
      // })

      db.ref('/sensors').set({
        sensor1: '1',
        sensor2: '2',
        sensor3: '3',
        sensor4: '4',
        sensor5: '5',

      })

      db.ref.('/sensors/').on('value', snapshot => {

      })
    }
  }
</script>

<style scoped>

</style>
