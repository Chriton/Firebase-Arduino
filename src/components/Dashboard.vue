<template>
  <v-container fluid grid-list-lg>
    <v-layout row wrap justify-center>
      <v-flex xs12 sm12 md6>
        <v-card>
          <v-card-title><h4>Sensor1 Data</h4></v-card-title>
          <v-divider></v-divider>
          <v-list dense>
            <div v-if="sensorData == undefined">
              <v-list-tile>
                <v-list-tile-content>There is no sensor data available</v-list-tile-content>
              </v-list-tile>
            </div>
            <div v-else>
              <v-list-tile v-for="(value, propertyName, index) in sensorData" v-bind:key="sensorData.index">
                <v-list-tile-content>{{ index + 1 }}.{{ propertyName }}</v-list-tile-content>
                <v-list-tile-content class="align-end">{{ value }}</v-list-tile-content>
              </v-list-tile>
            </div>

          </v-list>
        </v-card>
      </v-flex>
    </v-layout>
  </v-container>

</template>

<script>
  import db from '@/components/firebaseInit'
  export default {
    name: "dashboard",
    data () {
      return {
        sensorData: { }
      }
    },
    created () {
      db.ref('sensors/sensor1').on('value', snapshot => {
        this.sensorData = snapshot.val();
      })
    }
  }
</script>

<style scoped>

</style>
